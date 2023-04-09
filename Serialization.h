#pragma once
#include "Graphic.h"

	using namespace System;
	using namespace System::IO;
	using namespace System::Runtime::Serialization;
	using namespace System::Xml;
	using namespace Graphic;

	//Класс, управляющий сохранением/загрузкой данных
	ref class SerializationData
	{
	public:
		//Загрузка
		Space^ Load(String^ url);
		//Сохранение
		bool Save(Space^ area, String^ url);
	};

