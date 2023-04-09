#include "View.h"

ClassDiagram::View::View(DataBlock ^data, Graphic::TypeObject type)
{
	InitializeComponent();
	this->data = data;
	this->type = type;
	if (type == Graphic::TypeObject::Interface)
	{
		tabControl->TabPages->Remove(tabPageAttr);
		this->Text = "Интерфейс";
	}
	else
	{
		this->Text = "Класс";
	}
	mods = gcnew array<String^>(3) { "Закрытый", "Публичный", "Защищенный" };
	//Заполнение данных
	FillData();
	//Установление значений по умолчанию
	SetDefaultData();
}

void ClassDiagram::View::FillData()
{
	textBoxTitle->Text = data->Title;
	//Заполнение атрибутов
	if (type == Graphic::TypeObject::Class)
	{
		IReadOnlyList<AttributeData^>^ attr = data->GetAttributes();
		int count_attr = data->CountAttributes();
		for (int i = 0; i < count_attr; i++)
		{
			gridAttr->Rows->Add();
			gridAttr["gridAttr_columnNumber", i]->Value = (i + 1).ToString();
			gridAttr["gridAttr_columnMod", i]->Value = mods[attr[i]->Access];
			gridAttr["gridAttr_columnName", i]->Value = attr[i]->Name;
			gridAttr["gridAttr_columnType", i]->Value = attr[i]->Type;
		}
	}
	//Заполнение методов
	//gridMethods_column
	IReadOnlyList<AttributeData^>^ methods = data->GetMethods();
	int count_methods = data->CountMethods();
	for (int i = 0; i < count_methods; i++)
	{
		gridMethods->Rows->Add();
		gridMethods["gridMethods_columnNumber", i]->Value = (i + 1).ToString();
		gridMethods["gridMethods_columnMod", i]->Value = mods[methods[i]->Access];
		gridMethods["gridMethods_columnName", i]->Value = methods[i]->Name;
		gridMethods["gridMethods_columnType", i]->Value = methods[i]->Type;
	}
}

void ClassDiagram::View::SetDefaultData()
{
	if (gridAttr->NewRowIndex >= 0)
	{
		gridAttr["gridAttr_columnNumber", gridAttr->NewRowIndex]->Value = gridAttr->NewRowIndex + 1;
		gridAttr["gridAttr_columnMod", gridAttr->NewRowIndex]->Value = mods[AccessModifier::PublicMode];
	}
	if (gridMethods->NewRowIndex >= 0)
	{
		gridMethods["gridMethods_columnNumber", gridMethods->NewRowIndex]->Value = gridMethods->NewRowIndex + 1;
		gridMethods["gridMethods_columnMod", gridMethods->NewRowIndex]->Value = mods[AccessModifier::PublicMode];
	}
}

AccessModifier ClassDiagram::View::StringToEnum(String^ str)
{
	for (int i = 0; i < 3; i++)
	{
		if (str == mods[i])
			return (AccessModifier)i;
	}
	return AccessModifier::PublicMode;
}

System::Void ClassDiagram::View::buttonAccept_Click(System::Object^ sender, System::EventArgs^ e)
{
	data->Clear();
	data->Title = textBoxTitle->Text;
	if (type == Graphic::TypeObject::Class)
	{
		int count_attr = gridAttr->RowCount-1;
		for (int i = 0; i < count_attr; i++)
		{
			AccessModifier access = StringToEnum(gridAttr["gridAttr_columnMod", i]->Value->ToString());
			if (gridAttr["gridAttr_columnName", i]->Value != nullptr && gridAttr["gridAttr_columnType", i]->Value != nullptr)
			{
				String^ title = gridAttr["gridAttr_columnName", i]->Value->ToString();
				String^ type = gridAttr["gridAttr_columnType", i]->Value->ToString();
				if (!String::IsNullOrEmpty(title) && !String::IsNullOrEmpty(type))
				{
					AttributeData^ a = gcnew AttributeData(access, title, type);
					data->AddAtribute(a);
				}
			}
		}
	}
	int count_methods = gridMethods->RowCount - 1;
	for (int i = 0; i < count_methods; i++)
	{
		AccessModifier access = StringToEnum(gridMethods["gridMethods_columnMod", i]->Value->ToString());
		if (gridMethods["gridMethods_columnName", i]->Value != nullptr && gridMethods["gridMethods_columnType", i]->Value != nullptr)
		{
			String^ title = gridMethods["gridMethods_columnName", i]->Value->ToString();
			String^ type = gridMethods["gridMethods_columnType", i]->Value->ToString();
			if (!String::IsNullOrEmpty(title) && !String::IsNullOrEmpty(type))
			{
				AttributeData^ a = gcnew AttributeData(access, title, type);
				data->AddMethod(a);
			}
		}
	}
	this->Close();
}

System::Void ClassDiagram::View::gridAttr_RowsAdded(System::Object^ sender, System::Windows::Forms::DataGridViewRowsAddedEventArgs^ e)
{
	if (gridAttr->NewRowIndex >= 0)
	{
		gridAttr["gridAttr_columnNumber", gridAttr->NewRowIndex]->Value = gridAttr->NewRowIndex + 1;
		gridAttr["gridAttr_columnMod", gridAttr->NewRowIndex]->Value = mods[AccessModifier::PublicMode];
	}
}

System::Void ClassDiagram::View::gridMethods_UserAddedRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowEventArgs^ e)
{
	if (gridMethods->NewRowIndex >= 0)
	{
		gridMethods["gridMethods_columnNumber", gridMethods->NewRowIndex]->Value = gridMethods->NewRowIndex + 1;
		gridMethods["gridMethods_columnMod", gridMethods->NewRowIndex]->Value = mods[AccessModifier::PublicMode];
	}
}

