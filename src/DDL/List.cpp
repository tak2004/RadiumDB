#include "RadiumDB/DDL/List.hpp"

namespace RadiumDB { namespace DDL {

RF_Type::Bool List::Validate(const DCL::Document& Object, RF_Type::UInt32 DataOffset)
{
    return false;    
}

void List::AcceptType(const RF_Type::String& Name, const RF_Type::String& Type)
{
    m_AcceptedTypes.Resize(m_AcceptedTypes.Count()+1);
    m_AcceptedTypes(m_AcceptedTypes.Count()-1) = Type;
}

const RF_Collect::Array<RF_Type::String>& List::GetAcceptedTypes()const
{
    return m_AcceptedTypes;
}

RF_Type::Bool List::IsAcceptedType(const RF_Type::String& Name) const
{
    RF_Type::Bool result = false;
    const RF_Type::String* name = &Name;
    
    if(RF_Algo::Exists(m_AcceptedTypes,
        [name](RF_Collect::Array<RF_Type::String>::ConstEnumeratorType& Enum) 
        {return *Enum == *name;}))
    { 
        result = true;
    }

    return result;
}

} }