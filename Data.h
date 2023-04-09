
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Runtime::Serialization;
using namespace System::IO;

//���������� ������������� �������
const int COUNT_ACCESS_MODIFIER = 3;
//����������� �������
enum AccessModifier
{
	PrivateMode,
	PublicMode,
	ProtectedMode
};
//����� ���������/������
#pragma once
[DataContract]
ref class AttributeData
{
private:
	[DataMember] int accessModifier;//����������� �������
	[DataMember] String^ name;//��������
	[DataMember] String^ type;//��� ������
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
	//����� ��������� ������ � �������
	String^ GetString();
};
//���������� ����� ������
[DataContract]
ref class DataBlock
{
private:
	[DataMember] String^ title;//���������
	[DataMember] List<AttributeData^> ^attributes;//������ ���������
	[DataMember] List<AttributeData^> ^methods;//������ �������
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
	//���������� ��������
	void AddAtribute(AttributeData ^value);
	//�������� ��������� �� ������ � ������
	void RemoveAttribute(int number);
	//���������� ������
	void AddMethod(AttributeData ^value);
	//�������� ������ �� ������ � ������
	void RemoveMethod(int number);
	//��������� �������� �� ������
	AttributeData^ GetAttribute(int number);
	//��������� ������ �� ������
	AttributeData^ GetMethod(int number);
	//��������� ���������� ���������
	int CountAttributes();
	//��������� ���������� �������
	int CountMethods();
	//��������� ����� ����� ������� ������
	int MaxLenghtText();
	String^ ListAttributesToString();
	String^ ListMethodsToString();

	//������� ������ ���������
	IReadOnlyList<AttributeData^>^ GetAttributes();
	//������� ������ �������
	IReadOnlyList<AttributeData^>^ GetMethods();
	//�������� ���� ���������
	void ClearAttributes();
	//�������� ���� �������
	void ClearMethods();
	//�������� ���� ������
	void Clear();
};
