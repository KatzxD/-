#include "Data.h"

AttributeData::AttributeData(int accessModifier, String^ name, String^ type)
{
	this->accessModifier = accessModifier;
	this->name = name;
	this->type = type;
}

String^ AttributeData::GetString()
{
	//Строка с данными
	String^ str = " "+Convert::ToString(modificators[accessModifier]) + "  " + name + " : " + type + "\n";
	return str;
}

DataBlock::DataBlock(String^ title)
{
	this->title = title;
	attributes = gcnew List<AttributeData^>();
	methods= gcnew List<AttributeData^>();
}

void DataBlock::AddAtribute(AttributeData ^value)
{
	attributes->Add(value);
}

void DataBlock::RemoveAttribute(int number)
{
	if (number >= 0 && number < attributes->Count)
		attributes->RemoveAt(number);
}

void DataBlock::AddMethod(AttributeData^ value)
{
	methods->Add(value);
}

void DataBlock::RemoveMethod(int number)
{
	if (number >= 0 && number < attributes->Count)
		methods->RemoveAt(number);
}

AttributeData^ DataBlock::GetAttribute(int number)
{
	if (number >= 0 && number < attributes->Count)
		return attributes[number];
	else
		return nullptr;
}

AttributeData^ DataBlock::GetMethod(int number)
{
	if (number >= 0 && number < attributes->Count)
		return methods[number];
	else
		return nullptr;
}

int DataBlock::CountAttributes()
{
	return attributes->Count;
}

int DataBlock::CountMethods()
{
	return methods->Count;
}

int DataBlock::MaxLenghtText()
{
	int max = 0;
	int attributes_count = CountAttributes();	
	for (int i = 0; i < attributes_count; i++)
	{
		if (attributes[i]->GetString()->Length > max)
		{
			max = attributes[i]->GetString()->Length;
		}
	}
	int methods_count = CountMethods();
	for (int i = 0; i < methods_count; i++)
	{
		if (methods[i]->GetString()->Length > max)
		{
			max = methods[i]->GetString()->Length;
		}
	}
	return max;
}

String^ DataBlock::ListAttributesToString()
{
	String^ result = "";
	int attributes_count = CountAttributes();
	if (attributes_count > 0)
	{
		for (int i = 0; i < attributes_count; i++)
		{
			result += attributes[i]->GetString();
		}
		result = result->Remove(result->Length - 1);
	}
	return result;
}

String^ DataBlock::ListMethodsToString()
{
	String^ result = "";
	int methods_count = CountMethods();
	if (methods_count > 0)
	{
		for (int i = 0; i < methods_count; i++)
		{
			result += methods[i]->GetString();
		}
		result = result->Remove(result->Length - 1);
	}
	return result;
}

IReadOnlyList<AttributeData^>^ DataBlock::GetAttributes()
{
	return attributes->AsReadOnly();
}

IReadOnlyList<AttributeData^>^ DataBlock::GetMethods()
{
	return methods->AsReadOnly();
}

void DataBlock::ClearAttributes()
{
	attributes->Clear();
}

void DataBlock::ClearMethods()
{
	methods->Clear();
}

void DataBlock::Clear()
{
	ClearAttributes();
	ClearMethods();
}
