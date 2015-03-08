#ifndef RDB_DDL_TEMPLATE_HPP
#define RDB_DDL_TEMPLATE_HPP

#include <RadonFramework/Radon.hpp>

#include <RadiumDB/DDL/Type.hpp>

namespace RadiumDB { namespace DDL {

class Template: public Type
{
public:
    class Member
    {
    public:
        RF_Type::String Name;
        RF_Type::String Type;
    };

    virtual RF_Type::Bool Validate(const DCL::Document& Object, 
                                   RF_Type::UInt32 DataOffset) override;
    
    RF_Type::Bool RegisterMember(const RF_Type::String& Name,
                                 const RF_Type::String& Type);
    RF_Type::Bool RegisterMember(const RF_Type::String& Name,
                                 const RF_Type::String& Type,
                                 const RF_Type::String& TypeParameter);
    const Member* GetMember(const RF_Type::String& Name)const;
    RF_Type::Bool IsRegisteredMember(const RF_Type::String& Name)const;
private:
    RF_Collect::Array<Member> m_Members;
};

} }

#endif // RDB_DDL_TEMPLATE_HPP
