#include "RadiumDB/DDL/DataDefinitionLanguage.hpp"

namespace RadiumDB { namespace DDL {

RF_Type::Bool DataDefinitionLanguage::IsRegisteredType(const RF_Type::String& Typename) const
{
    RF_Type::Bool result = false;
    return result;
}

RF_Type::Bool DataDefinitionLanguage::RegisterType(RF_Mem::AutoPointer<Type>& NewType)
{
    RF_Type::Bool result = false;
    return result;
}

RF_Type::Bool DataDefinitionLanguage::UnregisterType(const RF_Type::String& Typename)
{
    RF_Type::Bool result = false;
    return result;
}

const Type* DataDefinitionLanguage::GetType(const RF_Type::String& Typename) const
{
    const Type* result = nullptr;
    return result;
}

} }