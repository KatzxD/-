#include "Serialization.h"

    Space^ SerializationData::Load(String^ url)
    {
        NetDataContractSerializer^ formatter = gcnew NetDataContractSerializer();
        XmlReader^ writer = XmlReader::Create(url);
        Space^ area = (Space^)formatter->ReadObject(writer);
        writer->Close();
        return area;

    }
    bool SerializationData::Save(Space^ area, String^ url)
    {
        NetDataContractSerializer^ formatter = gcnew NetDataContractSerializer();
        XmlWriterSettings^ setting = gcnew XmlWriterSettings();
        setting->Indent = true;
        XmlWriter^ writer = XmlWriter::Create(url, setting);
        formatter->WriteObject(writer, area);
        writer->Close();
        return true;
    }
