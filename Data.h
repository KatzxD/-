
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::Serialization;
using namespace System::IO;

//Количество модификаторов доступа
const int COUNT_ACCESS_MODIFIER = 3;
//Модификатор доступа
enum AccessModifier
{
	PrivateMode,
	PublicMode,
	ProtectedMode
};
//Класс аттрибута/метода
#pragma once
[DataContract]
ref class AttributeData
{
private:
	[DataMember] int accessModifier;//Модификатор доступа
	[DataMember] String^ name;//Название
	[DataMember] String^ type;//Тип данных
	static array<String^> ^modificators;
	static AttributeData()
	{
		modificators = gcnew array<String^>(COUNT_ACCESS_MODIFIER);
		modificators[AccessModifier::PrivateMode] = "-";
		modificators[AccessModifier::PublicMode] = "+";
		modificators[AccessModifier::ProtectedMode] = "#";
	}
public:
	property AccessModifier Access
	{
		AccessModifier get() { return (AccessModifier)accessModifier; }
		void set(AccessModifier value) { accessModifier = value; }
	}
	property String^ Name
	{
		String^ get() { return name; }
		void set(String^ value) { name = value; }
	}
	property String^ Type
	{
		String^ get() { return type; }
		void set(String^ value) { type = value; }
	}
	AttributeData(int accessModifier, String^ name, String^ type);
	//Метод получения строки с данными
	String^ GetString();
};
//Содержимое блока данных
[DataContract]
ref class DataBlock
{
private:
	[DataMember] String^ title;//Заголовок
	[DataMember] List<AttributeData^> ^attributes;//Список атрибутов
	[DataMember] List<AttributeData^> ^methods;//Список методов
public:
	DataBlock(String^ title);
	property String^ Title
	{
		String^ get()
		{
			return title;
		}
		void set(String^ value)
		{
			title = value;
		}
	}
	//Добавление атрибута
	void AddAtribute(AttributeData ^value);
	//Удаление аттрибута по номеру в списке
	void RemoveAttribute(int number);
	//Добавление метода
	void AddMethod(AttributeData ^value);
	//Удаление метода по номеру в списке
	void RemoveMethod(int number);
	//Получение атрибута по номеру
	AttributeData^ GetAttribute(int number);
	//Получение метода по номеру
	AttributeData^ GetMethod(int number);
	//Получение количества атрибутов
	int CountAttributes();
	//Получение количества методов
	int CountMethods();
	//Получение длины самой длинной строки
	int MaxLenghtText();
	String^ ListAttributesToString();
	String^ ListMethodsToString();

	//Возврат списка атрибутов
	IReadOnlyList<AttributeData^>^ GetAttributes();
	//Возврат списка методов
	IReadOnlyList<AttributeData^>^ GetMethods();
	//Удаление всех атрибутов
	void ClearAttributes();
	//Удаление всех методов
	void ClearMethods();
	//Удаление всех данных
	void Clear();
};
