#ifndef RDB_DCL_DOCUMENT_HPP
#define RDB_DCL_DOCUMENT_HPP

#include <RadonFramework/Radon.hpp>
#include <RadonFramework/Util/UUID.hpp>

namespace RadiumDB { namespace DCL {

class Document
{
public:
    void SetType(const RF_Type::String& Typename);
    RF_Util::UUID ID()const;
    RF_Type::Bool SetStr(const RF_Type::String& Path);
    RF_Type::Bool SetStr(const RF_Type::String& Path, const RF_Type::String& Value);
    RF_Type::String GetStr(const RF_Type::String& Path);
private:
    RF_Util::UUID m_ID;
    RF_Type::String m_Type;
    RF_Mem::AutoPointerArray<RF_Type::UInt8> m_ByteCode;
};

RF_Type::Bool Document::SetStr(const RF_Type::String& Path, const RF_Type::String& Value)
{
    return false;
}

RF_Type::Bool Document::SetStr(const RF_Type::String& Path)
{
    return false;
}

RF_Type::String Document::GetStr(const RF_Type::String& Path)
{
    return "";
}

}
}

#endif // RDB_DCL_DOCUMENT_HPP
