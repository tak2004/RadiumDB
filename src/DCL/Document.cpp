#include "RadiumDB/DCL/Document.hpp"

namespace RadiumDB { namespace DCL {

void Document::SetType(const RF_Type::String& Typename)
{
    m_Type = Typename;
}

RF_Util::UUID Document::ID() const
{
    return m_ID;
}

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
    return ""_rfs;
}

} }