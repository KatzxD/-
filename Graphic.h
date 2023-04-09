#pragma once
#include "LineMath.h"
#include "Data.h"

namespace Graphic
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::Serialization;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::IO;


	//Тип соединения
	enum class TypeConnection
	{
		
		Dependency=0,//Зависимость
		Association=1,//Ассоциация
		Aggregation=2,//Агрегация
		Composition=3,//Композиция
		Generalization=4,//Наследование
		Realization=5//Реализация
	};
	//Тип объекта
	const int TypeObjectOFFSET = 6;
	enum TypeObject
	{
		Class=6,//Класс
		Interface=7,//Интерфейс
	};

	//Дизайн рисования объектов
	public ref struct  Design
	{
		Brush^ BrushLine;//Цвет границ объектов
		Brush^ BrushText;//Цвет текста
		Brush^ BrushFill;//Цвет заполнения объекта
		Pen^ PenFill;//Границы фигуры
		Pen^ PenLine;//Линия соединения
		Font^ FontText;//Шрифт
		Design();
	};

	//Базовый элемент рисования
	[DataContract]
	public ref class BasicObject abstract
	{
	private:
		//Метод, срабатывающий после десериализации, для установления значений по умолчанию
		[OnDeserializing] void AfterDeserialize(StreamingContext context);
	public:
		Design^ prop;//Свойства графики
		BasicObject();
		//Метод, определяющий существование своей отрисованной фигуры на поле по точке
		virtual bool Exist(Point point) = 0;
		//Метод отрисовки объекта
		virtual void Paint() = 0;
	};
	//Базовый объект рисования фигуры
	[DataContract]
	public ref class PaintObject abstract :BasicObject
	{
		 Point location;//Координаты фигуры
		 System::Drawing::Size size;//Размер
	protected:
		array<Point>^ points;//Точки построения фигуры
		//Метод перерасчета контура фигуры при изменении местроположения фигуры
		virtual void ChangeLocation();
	public:
		[DataMember(Order = 0)] property System::Drawing::Size Size
		{
			System::Drawing::Size get() { return size; }
			void set(System::Drawing::Size size) 
			{ 
				this->size = size;
				if(!location.IsEmpty)
					ChangeLocation();
			}
		}
		[DataMember(Order = 1)] property Point Location
		{
			Point get() { return location; }
			void set(Point loc)
			{
				location = loc;
				ChangeLocation();
			}
		}
		PaintObject(Point loc, System::Drawing::Size size);
		PaintObject(Point loc);
		
		//Метод, определяющий точку пересечения своего контура с заданной линией
		virtual Point Intersect(Point p1, Point p2);
	};

	//Объект соединения фигур
	[DataContract]
	public ref class Connector :BasicObject
	{
	private:
		//Метод, срабатывающий после десериализации, для установления значений по умолчанию
		[OnDeserialized] void AfterDeserialize(StreamingContext context);
	public:
		[DataMember] int type_connection;//Тип соединения
		[DataMember] static const float OFFSET = 5;//Погрешность при попадании курсора на линии
		//Метод, определяющий попадание точки на линию с учетом погрешности
		static float Function(Point point1, Point point2, Point search_point, float offset);
		[DataMember] PaintObject^ ObjectStart;//Начальный объект
		[DataMember] PaintObject^ ObjectEnd;//Конечный объект
		Point FlowPoint;//Временная точка, когда неопределен конечный объект
		Connector(PaintObject^ ObjectStart, Point flow_point, TypeConnection type);
		//Метод, присоединяющий конец линии к заданному объекту
		void ConnectFigure(PaintObject^ ObjectEnd);
		bool Exist(Point point) override;
		void Paint() override;
		//Метод изменения типа линии
		void SetTypeLine();
	};

	//ОБЛАСТЬ РИСОВАНИЯ

	[DataContract]
	public ref class Space
	{
	private:
		[DataMember(Order = 0)] List<PaintObject^>^ objects;//Список объектов
		[DataMember(Order = 1)] List<Connector^>^ connections;//Список соединений
		//Метод, удаляющий соединения с заданным элементом
		void RemoveConnections(PaintObject^ f);
		bool ExistConnection(Connector^ line);
	public:
		static Graphics^ g;//Инструмент рисования
		Image^ image;//Область рисования
		Space(System::Drawing::Size size);
		//Метод, изменяющий размер поля
		Image^ Resize(System::Drawing::Size new_size);
		//Количество объектов
		int CountObjects();
		//Метод добавления фигуры
		void AddObject(Point Location, TypeObject type);
		//Метод добавления соединения
		bool AddConnection(Connector^ line);
		//Метод удаления фигуры
		void RemoveBlock(Point point);
		//Метод удаления линии
		void RemoveConnection(Connector^ line);
		//Получение фигуры по координатам
		PaintObject^ GetBlock(Point point);
		//Получение линии по координатам
		Connector^ GetConnection(Point point);
		//Получение объекта поля рисования по координатам
		BasicObject^ GetObject(Point point);
		//Получение списка соединений, соединенных с заданным элементом
		List<Connector^>^ GetConnections(PaintObject^ obj);
		//Удаление всех объектов с поля
		void Clear();
		//Метод рисования объектов на поле
		void Paint();
	};


	//ОБЪЕКТЫ РИСОВАНИЯ

	//Дополнительный дизайн блока
	ref struct FontBlock
	{
		Font^ FontType;
		Font^ FontTitle;
		Font^ FontMember;
		FontBlock();
	};
	
	//Класс, определяющий блок c данными объекта
	[DataContract]
	public ref class Block : public PaintObject
	{
	private:
		//Константы
		[DataMember] const int EMPTY_MEMBER_HEIGHT = 30;
		[DataMember] const int EMPTY_WIDTH_BLOCK = 150;
		[DataMember] const int HeightType = 20;//Высота типа блока
		[DataMember] const int HeightTitle = 25;//Высота заголовка блока
		[DataMember] const int HeightMember = 20;//Высота члена блока (атрибут, метод)
		[DataMember] const double WidthTitleChar = 13;//Ширина символа заголовка
		[DataMember] const double WidthMemberChar = 10;//Ширина символа заголовка
		//Количество модификаторов доступа
		static const int COUNT_TYPE_OF_BLOCK = 2;
		//Стандартные названия типов блоков
		static array<String^>^ defaultTitles;
		
		//Данные блока
		[DataMember] DataBlock ^data;
		static FontBlock ^font;
		//Тип блока
		[DataMember] int blockType;
		
		static Block() 
		{
			defaultTitles = gcnew array<String^>(COUNT_TYPE_OF_BLOCK);
			defaultTitles[TypeObject::Class - TypeObjectOFFSET] = "<<Класс>>";
			defaultTitles[TypeObject::Interface - TypeObjectOFFSET] = "<<Интерфейс>>";
			font = gcnew FontBlock();
		}
	public:
		Block(Point loc, TypeObject type);
		property DataBlock^ Data
		{
			DataBlock^ get() { return data; }
			void set(DataBlock^ value) 
			{
				if (value != nullptr)
				{
					this->data = value;
					this->Size=GetSize();
				}
					
			}
		}
		property TypeObject BlockType 
		{
			TypeObject get() { return (TypeObject)blockType; }
		}
		bool Exist(Point point) override;
		void Paint() override;
		//Получение размера фигуры
		System::Drawing::Size GetSize();
		//Обновление размера фигуры
		void UpdateSize();
		//Получение размера области атрибутов
		System::Drawing::Size GetSizeAttributes();
		System::Drawing::Size GetSizeMethods();
		//Метод рисования текста
		void DrawText(String^ text, Rectangle r, Font^ font);
		void DrawText(String^ text, Rectangle r, Font^ font, StringAlignment aligment);
	};

}

