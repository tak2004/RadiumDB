#ifndef RDB_DDL_LIST_HPP
#define RDB_DDL_LIST_HPP

#include <RadonFramework/Radon.hpp>

#include <RadiumDB/DDL/Type.hpp>

namespace RadiumDB { namespace DDL {

class List: public Type
{
public:
    virtual RF_Type::Bool Validate(const DCL::Document& Object,
                                    RF_Type::UInt32 DataOffset) override;

    void AcceptType(const RF_Type::String& Name, const RF_Type::String& Type);
    const RF_Collect::Array<RF_Type::String>& GetAcceptedTypes()const;
    RF_Type::Bool IsAcceptedType(const RF_Type::String& Name)const;
private:
    RF_Collect::Array<RF_Type::String> m_AcceptedTypes;
};

} }

#endif // RDB_DDL_LIST_HPP
