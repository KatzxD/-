#include "Graphic.h"

namespace Graphic
{
	//
	//Дизайн рисования объектов
	//
	Design::Design()
	{
		//Установка значений по умолчанию
		this->BrushLine = gcnew SolidBrush(Color::Black);
		this->BrushText = gcnew SolidBrush(Color::Green);
		//this->BrushFill = gcnew SolidBrush(Color::White);
		this->BrushFill = gcnew SolidBrush(Color::FromArgb(234,210,185));
		this->PenFill = gcnew Pen(BrushLine, 2);
		this->PenLine = gcnew Pen(BrushLine, 2);
		this->FontText = gcnew Font("Arial", 12);
	}
	//
	//Базовый элемент рисования
	//
	void BasicObject::AfterDeserialize(StreamingContext context)
	{
		this->prop = gcnew Design();
	}
	BasicObject::BasicObject()
	{
		prop = gcnew Design();
	}
	//
	//Базовый объект рисования фигуры
	//
	void PaintObject::ChangeLocation()
	{
		Point LeftTop = Point(Location.X - Size.Width / 2, Location.Y - Size.Height / 2);
		Rectangle r = Rectangle(LeftTop, Size);
		points = gcnew array<Point>(4)
		{
			Point(r.Left, r.Top),
				Point(r.Right, r.Top),
				Point(r.Right, r.Bottom),
				Point(r.Left, r.Bottom)
		};
	}

	PaintObject::PaintObject(Point loc, System::Drawing::Size size) :BasicObject()
	{
		this->size = size;
		this->Location = loc;
	}
	PaintObject::PaintObject(Point loc)
	{
		this->Location = loc;
	}

	Point PaintObject::Intersect(Point point1, Point point2)
	{
		array<array<Point>^>^ pairs = gcnew array<array<Point>^>(4)
		{
			gcnew array<Point>(2) { points[0], points[1] },
				gcnew array<Point>(2) { points[1], points[2] },
				gcnew array<Point>(2) { points[2], points[3] },
				gcnew array<Point>(2) { points[3], points[0] }
		};
		for each (array<Point> ^ pair in pairs)
		{
			Point intersect_point = cross(point1, point2, pair[0], pair[1]);
			if (intersect_point != Point::Empty)
			{
				return intersect_point;
			}
		}
		return Point::Empty;
	}

	//Объект соединения фигур

	void Connector::AfterDeserialize(StreamingContext context)
	{
		SetTypeLine();
	}

	float Connector::Function(Point point1, Point point2, Point search_point, float offset)
	{
		float x = (float)(search_point.X - point1.X + offset) * (float)(point2.Y - point1.Y);
		float y = (float)(search_point.Y - point1.Y + offset) * (float)(point2.X - point1.X);
		return x - y;
	}

	Connector::Connector(PaintObject^ ObjectStart, Point flow_point, TypeConnection type) : BasicObject()
	{
		this->ObjectStart = ObjectStart;
		this->FlowPoint = flow_point;
		type_connection = (int)type;
		SetTypeLine();
	}

	void Connector::ConnectFigure(PaintObject^ f)
	{
		this->ObjectEnd = f;
	}

	bool Connector::Exist(Point point)
	{
		float t1 = Function(ObjectStart->Location, ObjectEnd->Location, point, OFFSET);
		float t2 = Function(ObjectStart->Location, ObjectEnd->Location, point, -OFFSET);
		float x_min = Math::Min(ObjectStart->Location.X, ObjectEnd->Location.X) - OFFSET / 2;
		float x_max = Math::Max(ObjectStart->Location.X, ObjectEnd->Location.X) + OFFSET / 2;
		float y_min = Math::Min(ObjectStart->Location.Y, ObjectEnd->Location.Y) - OFFSET / 2;
		float y_max = Math::Max(ObjectStart->Location.Y, ObjectEnd->Location.Y) + OFFSET / 2;
		if (((t1 < 0 && t2 > 0) || (t2 < 0 && t1 > 0)) &&
			point.X > x_min && point.X < x_max &&
			point.Y > y_min && point.Y < y_max)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Connector::Paint()
	{

		if (ObjectEnd == nullptr)
		{
			Point point1 = ObjectStart->Intersect(ObjectStart->Location, FlowPoint);
			if (!point1.IsEmpty)
			{
				Space::g->DrawLine(prop->PenLine, point1, FlowPoint);
			}
		}
		else
		{
			Point point1 = ObjectStart->Intersect(ObjectStart->Location, ObjectEnd->Location);
			Point point2 = ObjectEnd->Intersect(ObjectStart->Location, ObjectEnd->Location);
			if (!point1.IsEmpty && !point2.IsEmpty)
			{
				Space::g->DrawLine(prop->PenLine, point1, point2);
			}
		}

	}

	void Connector::SetTypeLine()
	{
		switch ((TypeConnection)type_connection)
		{
		case TypeConnection::Dependency:
		{
			prop->PenLine->DashStyle = DashStyle::Dash;
			prop->PenLine->CustomEndCap = gcnew AdjustableArrowCap(8, 8, false);
			break;
		}
		case TypeConnection::Association:
		{
			prop->PenLine->DashStyle = DashStyle::Solid;
			prop->PenLine->CustomEndCap = gcnew AdjustableArrowCap(8, 8, false);
			break;
		}
		case TypeConnection::Aggregation:
		{
			prop->PenLine->DashStyle = DashStyle::Solid;
			//Определение точек ромба
			GraphicsPath^ path = gcnew GraphicsPath();
			path->AddLine(Point(0, 0), Point(-5, -8));
			path->AddLine(Point(-5, -8), Point(0, -16));
			path->AddLine(Point(0, -16), Point(5, -8));
			path->AddLine(Point(5, -8), Point(0, 0));
			CustomLineCap^ custom_cup = gcnew CustomLineCap(nullptr, path);
			custom_cup->BaseInset = 16;
			prop->PenLine->CustomEndCap = custom_cup;
			break;
		}
		case TypeConnection::Composition:
		{
			prop->PenLine->DashStyle = DashStyle::Solid;
			//Определение точек ромба
			GraphicsPath^ path = gcnew GraphicsPath();
			path->AddLine(Point(0, 0), Point(-5, -8));
			path->AddLine(Point(-5, -8), Point(0, -16));
			path->AddLine(Point(0, -16), Point(5, -8));
			path->AddLine(Point(5, -8), Point(0, 0));
			CustomLineCap^ custom_cup = gcnew CustomLineCap(path, nullptr);
			custom_cup->BaseInset = 16;
			prop->PenLine->CustomEndCap = custom_cup;
			break;
		}
		case TypeConnection::Generalization:
		{
			prop->PenLine->DashStyle = DashStyle::Solid;
			//Определение точек треугольника
			GraphicsPath^ path = gcnew GraphicsPath();
			path->AddLine(Point(0, 0), Point(5,-8));
			path->AddLine(Point(5, -8), Point(-5, -8));
			path->AddLine(Point(-5, -8), Point(0, 0));
			CustomLineCap^ custom_cup = gcnew CustomLineCap(nullptr, path);
			custom_cup->BaseInset = 8;
			prop->PenLine->CustomEndCap = custom_cup;
			break;
		}
		case TypeConnection::Realization:
		{
			prop->PenLine->DashStyle = DashStyle::Dash;
			//Определение точек треугольника
			GraphicsPath^ path = gcnew GraphicsPath();
			path->AddLine(Point(0, 0), Point(5, -8));
			path->AddLine(Point(5, -8), Point(-5, -8));
			path->AddLine(Point(-5, -8), Point(0, 0));
			CustomLineCap^ custom_cup = gcnew CustomLineCap(nullptr, path);
			custom_cup->BaseInset = 8;
			prop->PenLine->CustomEndCap = custom_cup;
			break;
		}
		}
	}

	//ОБЛАСТЬ РИСОВАНИЯ

	void Space::RemoveConnections(PaintObject^ f)
	{
		for (int i = 0; i < connections->Count; i++)
		{
			if (connections[i]->ObjectStart == f || connections[i]->ObjectEnd == f)
			{
				connections->Remove(connections[i]);
				i--;
			}
		}
	}

	bool Space::ExistConnection(Connector^ line)
	{
		for each (Connector ^c in connections)
		{
			if (c == line)
			{
				return true;
			}
		}
		return false;
	}

	Space::Space(System::Drawing::Size size)
	{
		objects = gcnew List<PaintObject^>();
		connections = gcnew List<Connector^>();
		//Создание холста рисования (Bitmap)
		this->image = gcnew Bitmap(size.Width, size.Height);
		//Инициализация инструмента рисования
		g = Graphics::FromImage(image);
		//Сглаживание линий
		g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
	}

	Image^ Space::Resize(System::Drawing::Size new_Size)
	{
		if (!new_Size.IsEmpty)
		{
			this->image = gcnew Bitmap(new_Size.Width, new_Size.Height);
			g = Graphics::FromImage(image);
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
			return image;
		}
		else
		{
			return nullptr;
		}
	}

	int Space::CountObjects()
	{
		return objects->Count;
	}

	void Space::AddObject(Point Location, TypeObject type)
	{
		
		PaintObject^ obj= gcnew Block(Location, type);
		objects->Add(obj);
	}

	bool Space::AddConnection(Connector^ line)
	{
		bool result = false;
		if (!ExistConnection(line))
		{
			if (line->ObjectStart != nullptr)
			{
				if (line->ObjectEnd == nullptr)
				{
					connections->Add(line);
					result = true;
				}
				else
				{
					if (line->ObjectStart == line->ObjectEnd)
					{
						connections->Remove(line);
					}
				}
			}
		}
		return result;
	}

	void Space::RemoveBlock(Point point)
	{
		//Выбор фигуры для удаления
		PaintObject^ f = GetBlock(point);
		//Удаление связанных с ним связей
		if (f != nullptr)
		{
			RemoveConnections(f);
		}
		//Выбор линии для удаления
		Connector^ l = GetConnection(point);
		//Удаление фигуры
		objects->Remove(f);
		//Удаление линии
		connections->Remove(l);
	}

	void Space::RemoveConnection(Connector^ line)
	{
		connections->Remove(line);
	}

	PaintObject^ Space::GetBlock(Point point)
	{
		for (int i = objects->Count - 1; i >= 0; i--)
		{
			if (objects[i]->Exist(point))
			{
				PaintObject^ tmp = objects[i];
				objects->Remove(tmp);
				objects->Add(tmp);
				return tmp;
			}
		}
		return nullptr;
	}

	Connector^ Space::GetConnection(Point point)
	{
		for (int i = connections->Count - 1; i >= 0; i--)
		{
			if (connections[i]->Exist(point))
			{
				return connections[i];
			}
		}
		return nullptr;
	}

	BasicObject^ Space::GetObject(Point point)
	{
		BasicObject^ obj = nullptr;
		obj = GetBlock(point);
		if (obj == nullptr)
		{
			obj = GetConnection(point);
		}
		return obj;
	}

	List<Connector^>^ Space::GetConnections(PaintObject^ obj)
	{
		List<Connector^>^ l = gcnew List<Connector^>();
		for each (Connector ^ line in connections)
		{
			if (obj == line->ObjectStart || obj == line->ObjectEnd)
			{
				l->Add(line);
			}
		}
		return l;
	}

	void Space::Clear()
	{
		objects->Clear();
		connections->Clear();
		Paint();
	}

	void Space::Paint()
	{
		g->Clear(SystemColors::Control);
		for each (PaintObject ^ obj in objects)
		{
			obj->Paint();
		}
		for each (Connector ^ obj in connections)
		{
			obj->Paint();
		}
		
	}

	//ОБЪЕКТЫ РИСОВАНИЯ


	//Класс, определяющий блок c данными объекта

	Block::Block(Point loc, TypeObject type) :
		PaintObject(loc) 
	{
		switch (type)
		{
		case Graphic::Class:
			data = gcnew DataBlock("Имя класса");
			break;
		case Graphic::Interface:
			data = gcnew DataBlock("Имя интерфейса");
			break;
		default:
			break;
		}
		this->blockType = type;
		this->Size = GetSize();
		
		
	}

	void Block::Paint()
	{
		
		//Вычисление размеров прямоугольников
		System::Drawing::Size size_type = System::Drawing::Size(Size.Width,HeightType);
		System::Drawing::Size size_title = System::Drawing::Size(Size.Width, HeightTitle);
		System::Drawing::Size size_head = System::Drawing::Size(Size.Width, HeightType+ HeightTitle);
		System::Drawing::Size size_body_attr = GetSizeAttributes();
		System::Drawing::Size size_body_methods = GetSizeMethods();

		//
		//Рисование шапки
		//
		Point LeftTop = Point(Location.X - Size.Width / 2, Location.Y - Size.Height / 2);
		//Рисования заголовка блока
		System::Drawing::Rectangle rectangle_head = System::Drawing::Rectangle(LeftTop, size_head);
		Space::g->DrawRectangle(prop->PenFill, rectangle_head);
		Space::g->FillRectangle(prop->BrushFill, rectangle_head);
		//Рисование текста типа блока
		System::Drawing::Rectangle rectangle_type = System::Drawing::Rectangle(LeftTop, size_type);
		DrawText(defaultTitles[blockType-TypeObjectOFFSET], rectangle_type, font->FontType);
		//Рисование текста заголовка
		LeftTop = Point(rectangle_type.Left, rectangle_type.Bottom);
		System::Drawing::Rectangle rectangle_title = System::Drawing::Rectangle(LeftTop, size_title);
		DrawText(data->Title, rectangle_title, font->FontTitle);
		//
		//Рисование атрибутов и методов класса
		//
		if (this->BlockType == TypeObject::Class)
		{
			//Рисование атрибутов
			LeftTop = Point(rectangle_title.Left, rectangle_title.Bottom);
			System::Drawing::Rectangle body_attr = System::Drawing::Rectangle(LeftTop, size_body_attr);
			//Отрисовка тела атрибутов
			Space::g->DrawRectangle(prop->PenFill, body_attr);
			Space::g->FillRectangle(prop->BrushFill, body_attr);
			if (data->CountAttributes() > 0)
			{
				//Отрисовка строк
				DrawText(data->ListAttributesToString(), body_attr, font->FontMember, StringAlignment::Near);
			}
			rectangle_title = body_attr;
		}
		
		//Рисование методов
		LeftTop = Point(rectangle_title.Left, rectangle_title.Bottom);
		//Отрисовка тела методов
		System::Drawing::Rectangle body_methods = System::Drawing::Rectangle(LeftTop, size_body_methods);
		Space::g->DrawRectangle(prop->PenFill, body_methods);
		Space::g->FillRectangle(prop->BrushFill, body_methods);
		if (data->CountMethods() > 0)
		{
			//Отрисовка строк
			DrawText(data->ListMethodsToString(), body_methods, font->FontMember, StringAlignment::Near);
		}
		
	}

	System::Drawing::Size Block::GetSize()
	{
		int height = HeightType + HeightTitle;
		if (this->BlockType == TypeObject::Class)
		{
			if (data->CountAttributes() > 0)
				height += data->CountAttributes() * HeightMember;
			else
				height += EMPTY_MEMBER_HEIGHT;
		}
		if (data->CountMethods() > 0)
			height += data->CountMethods() * HeightMember;
		else
			height += EMPTY_MEMBER_HEIGHT;

		//Вычисление максимальной ширины объекта
		int title_width = data->Title->Length * WidthTitleChar;
		int attr_width = data->MaxLenghtText() * WidthMemberChar;
		int max_width = Math::Max(title_width, attr_width);
		if (max_width < EMPTY_WIDTH_BLOCK)
			max_width = EMPTY_WIDTH_BLOCK;
		return System::Drawing::Size(max_width, height);
	}

	void Block::UpdateSize()
	{
		this->Size = GetSize();
	}

	System::Drawing::Size Block::GetSizeAttributes()
	{
		int height = 0;
		if (data->CountAttributes() > 0)
			height += data->CountAttributes() * HeightMember;
		else
			height += EMPTY_MEMBER_HEIGHT;
		return System::Drawing::Size(Size.Width, height);
	}

	System::Drawing::Size Block::GetSizeMethods()
	{
		int height = 0;
		if (data->CountMethods() > 0)
			height += data->CountMethods() * HeightMember;
		else
			height += EMPTY_MEMBER_HEIGHT;
		return System::Drawing::Size(Size.Width, height);
	}

	bool Block::Exist(Point point)
	{
		Point LeftTop = Point(Location.X - Size.Width / 2, Location.Y - Size.Height / 2);
		if (point.X > LeftTop.X && point.X<LeftTop.X + Size.Width &&
			point.Y>LeftTop.Y && point.Y < LeftTop.Y + Size.Height)
		{
			return true;
		}
		else { return false; }
	}
	void Block::DrawText(String^ text, Rectangle r, Font^ font)
	{
		//Рисование текста
		StringFormat^ format = gcnew StringFormat(StringFormatFlags::NoClip);
		format->Alignment = StringAlignment::Center;
		format->LineAlignment = StringAlignment::Center;
		Space::g->DrawString(text, font, prop->BrushLine, r, format);
	}

	void Block::DrawText(String^ text, Rectangle r, Font^ font, StringAlignment aligment)
	{
		//Рисование текста
		StringFormat^ format = gcnew StringFormat(StringFormatFlags::NoClip);
		format->Alignment = aligment;
		format->LineAlignment = StringAlignment::Center;
		Space::g->DrawString(text, font, prop->BrushLine, r, format);
	}

	FontBlock::FontBlock()
	{
		this->FontType = gcnew Font("Arial", 10,FontStyle::Italic);
		this->FontTitle = gcnew Font("Arial", 14, FontStyle::Bold);
		this->FontMember = gcnew Font("Arial", 11);
	}
}
