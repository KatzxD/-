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


	//��� ����������
	enum class TypeConnection
	{
		
		Dependency=0,//�����������
		Association=1,//����������
		Aggregation=2,//���������
		Composition=3,//����������
		Generalization=4,//������������
		Realization=5//����������
	};
	//��� �������
	const int TypeObjectOFFSET = 6;
	enum TypeObject
	{
		Class=6,//�����
		Interface=7,//���������
	};

	//������ ��������� ��������
	public ref struct  Design
	{
		Brush^ BrushLine;//���� ������ ��������
		Brush^ BrushText;//���� ������
		Brush^ BrushFill;//���� ���������� �������
		Pen^ PenFill;//������� ������
		Pen^ PenLine;//����� ����������
		Font^ FontText;//�����
		Design();
	};

	//������� ������� ���������
	[DataContract]
	public ref class BasicObject abstract
	{
	private:
		//�����, ������������� ����� ��������������, ��� ������������ �������� �� ���������
		[OnDeserializing] void AfterDeserialize(StreamingContext context);
	public:
		Design^ prop;//�������� �������
		BasicObject();
		//�����, ������������ ������������� ����� ������������ ������ �� ���� �� �����
		virtual bool Exist(Point point) = 0;
		//����� ��������� �������
		virtual void Paint() = 0;
	};
	//������� ������ ��������� ������
	[DataContract]
	public ref class PaintObject abstract :BasicObject
	{
		 Point location;//���������� ������
		 System::Drawing::Size size;//������
	protected:
		array<Point>^ points;//����� ���������� ������
		//����� ����������� ������� ������ ��� ��������� ��������������� ������
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
		
		//�����, ������������ ����� ����������� ������ ������� � �������� ������
		virtual Point Intersect(Point p1, Point p2);
	};

	//������ ���������� �����
	[DataContract]
	public ref class Connector :BasicObject
	{
	private:
		//�����, ������������� ����� ��������������, ��� ������������ �������� �� ���������
		[OnDeserialized] void AfterDeserialize(StreamingContext context);
	public:
		[DataMember] int type_connection;//��� ����������
		[DataMember] static const float OFFSET = 5;//����������� ��� ��������� ������� �� �����
		//�����, ������������ ��������� ����� �� ����� � ������ �����������
		static float Function(Point point1, Point point2, Point search_point, float offset);
		[DataMember] PaintObject^ ObjectStart;//��������� ������
		[DataMember] PaintObject^ ObjectEnd;//�������� ������
		Point FlowPoint;//��������� �����, ����� ����������� �������� ������
		Connector(PaintObject^ ObjectStart, Point flow_point, TypeConnection type);
		//�����, �������������� ����� ����� � ��������� �������
		void ConnectFigure(PaintObject^ ObjectEnd);
		bool Exist(Point point) override;
		void Paint() override;
		//����� ��������� ���� �����
		void SetTypeLine();
	};

	//������� ���������

	[DataContract]
	public ref class Space
	{
	private:
		[DataMember(Order = 0)] List<PaintObject^>^ objects;//������ ��������
		[DataMember(Order = 1)] List<Connector^>^ connections;//������ ����������
		//�����, ��������� ���������� � �������� ���������
		void RemoveConnections(PaintObject^ f);
		bool ExistConnection(Connector^ line);
	public:
		static Graphics^ g;//���������� ���������
		Image^ image;//������� ���������
		Space(System::Drawing::Size size);
		//�����, ���������� ������ ����
		Image^ Resize(System::Drawing::Size new_size);
		//���������� ��������
		int CountObjects();
		//����� ���������� ������
		void AddObject(Point Location, TypeObject type);
		//����� ���������� ����������
		bool AddConnection(Connector^ line);
		//����� �������� ������
		void RemoveBlock(Point point);
		//����� �������� �����
		void RemoveConnection(Connector^ line);
		//��������� ������ �� �����������
		PaintObject^ GetBlock(Point point);
		//��������� ����� �� �����������
		Connector^ GetConnection(Point point);
		//��������� ������� ���� ��������� �� �����������
		BasicObject^ GetObject(Point point);
		//��������� ������ ����������, ����������� � �������� ���������
		List<Connector^>^ GetConnections(PaintObject^ obj);
		//�������� ���� �������� � ����
		void Clear();
		//����� ��������� �������� �� ����
		void Paint();
	};


	//������� ���������

	//�������������� ������ �����
	ref struct FontBlock
	{
		Font^ FontType;
		Font^ FontTitle;
		Font^ FontMember;
		FontBlock();
	};
	
	//�����, ������������ ���� c ������� �������
	[DataContract]
	public ref class Block : public PaintObject
	{
	private:
		//���������
		[DataMember] const int EMPTY_MEMBER_HEIGHT = 30;
		[DataMember] const int EMPTY_WIDTH_BLOCK = 150;
		[DataMember] const int HeightType = 20;//������ ���� �����
		[DataMember] const int HeightTitle = 25;//������ ��������� �����
		[DataMember] const int HeightMember = 20;//������ ����� ����� (�������, �����)
		[DataMember] const double WidthTitleChar = 13;//������ ������� ���������
		[DataMember] const double WidthMemberChar = 10;//������ ������� ���������
		//���������� ������������� �������
		static const int COUNT_TYPE_OF_BLOCK = 2;
		//����������� �������� ����� ������
		static array<String^>^ defaultTitles;
		
		//������ �����
		[DataMember] DataBlock ^data;
		static FontBlock ^font;
		//��� �����
		[DataMember] int blockType;
		
		static Block() 
		{
			defaultTitles = gcnew array<String^>(COUNT_TYPE_OF_BLOCK);
			defaultTitles[TypeObject::Class - TypeObjectOFFSET] = "<<�����>>";
			defaultTitles[TypeObject::Interface - TypeObjectOFFSET] = "<<���������>>";
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
		//��������� ������� ������
		System::Drawing::Size GetSize();
		//���������� ������� ������
		void UpdateSize();
		//��������� ������� ������� ���������
		System::Drawing::Size GetSizeAttributes();
		System::Drawing::Size GetSizeMethods();
		//����� ��������� ������
		void DrawText(String^ text, Rectangle r, Font^ font);
		void DrawText(String^ text, Rectangle r, Font^ font, StringAlignment aligment);
	};

}

