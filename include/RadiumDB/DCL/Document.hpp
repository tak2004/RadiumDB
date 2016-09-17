#ifndef RDB_DCL_DOCUMENT_HPP
#define RDB_DCL_DOCUMENT_HPP

#include <RadonFramework/Radon.hpp>
#include <RadonFramework/Util/UUID.hpp>

namespace RadiumDB { namespace DCL {

class Document
{
public:
    /// Change the document type to the specified typename.
    void SetType(const RF_Type::String& Typename);
    /// Return the document unique identifier.
    RF_Util::UUID ID()const;
    RF_Type::Bool SetStr(const RF_Type::String& Path);
    RF_Type::Bool SetStr(const RF_Type::String& Path, const RF_Type::String& Value);
    RF_Type::String GetStr(const RF_Type::String& Path);
private:
    RF_Util::UUID m_ID;
    RF_Type::String m_Type;
    RF_Mem::AutoPointerArray<RF_Type::UInt8> m_ByteCode;
};

} }

#endif // RDB_DCL_DOCUMENT_HPP
