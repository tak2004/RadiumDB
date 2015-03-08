#include "RadiumDB/DDL/Template.hpp"

namespace RadiumDB { namespace DDL {

RF_Type::Bool Template::Validate(const DCL::Document& Object, RF_Type::UInt32 DataOffset)
{
    return false;    
}

RF_Type::Bool Template::RegisterMember(const RF_Type::String& Name, 
                                       const RF_Type::String& Type)
{
    RF_Type::Bool result = false;
    return result;
}

RF_Type::Bool Template::RegisterMember(const RF_Type::String& Name, 
    const RF_Type::String& Type, const RF_Type::String& TypeParameter)
{
    RF_Type::Bool result = false;
    return result;
}

const Template::Member* Template::GetMember(const RF_Type::String& Name) const
{
    const Member* result = 0;
    return result;
}

RF_Type::Bool Template::IsRegisteredMember(const RF_Type::String& Name) const
{
    RF_Type::Bool result = false;
    const RF_Type::String* name = &Name;
    if(RF_Algo::Exists(m_Members,
        [name](RF_Collect::Array<Member>::ConstEnumeratorType& Enum) {return Enum->Name == *name;}))
        result = true;
    return result;
}

} }