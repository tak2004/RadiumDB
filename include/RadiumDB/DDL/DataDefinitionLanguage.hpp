#ifndef RDB_DDL_DATADEFINITIONLANGUAGE_HPP
#define RDB_DDL_DATADEFINITIONLANGUAGE_HPP

#include <RadonFramework/Radon.hpp>

#include <RadiumDB/DDL/Type.hpp>

namespace RadiumDB { namespace DDL {

class DataDefinitionLanguage
{
public:
    RF_Type::Bool IsRegisteredType(const RF_Type::String& Typename)const;
    RF_Type::Bool RegisterType(RF_Mem::AutoPointer<Type>& NewType);
    RF_Type::Bool UnregisterType(const RF_Type::String& Typename);
    const Type* GetType(const RF_Type::String& Typename)const;
private:
    RF_Collect::AutoVector<Type> m_Types;
    RF_Collect::HashMap<RF_Type::UInt32, Type*> m_TypeLookup;
};

} }

#endif // RDB_DDL_DATADEFINITIONLANGUAGE_HPP
