#ifndef RDB_DDL_TYPE_HPP
#define RDB_DDL_TYPE_HPP

#include <RadonFramework/Radon.hpp>

namespace RadiumDB { namespace DCL {

class Document;

} }

namespace RadiumDB { namespace DDL {

class Type
{
public:
    virtual RF_Type::Bool Validate(const DCL::Document& Object, 
                                   RF_Type::UInt32 DataOffset) = 0;
    void Name(const RF_Type::String& NewName);
    const RF_Type::String& Name()const;
private:
    RF_Type::String m_Name;
};

} }

#endif // RDB_DDL_TYPE_HPP
