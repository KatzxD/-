#pragma once
#include "Graphic.h"

	using namespace System;
	using namespace System::IO;
	using namespace System::Runtime::Serialization;
	using namespace System::Xml;
	using namespace Graphic;

	//�����, ����������� �����������/��������� ������
	ref class SerializationData
	{
	public:
		//��������
		Space^ Load(String^ url);
		//����������
		bool Save(Space^ area, String^ url);
	};

