#include "RadiumDB/DDL/Type.hpp"

namespace RadiumDB { namespace DDL {

void Type::Name(const RF_Type::String& NewName)
{
    m_Name = NewName;
}

const RF_Type::String& Type::Name()const
{
    return m_Name;
}

} }