#ifndef RDB_RADIUMDB_HPP
#define RDB_RADIUMDB_HPP

#include <RadonFramework/Radon.hpp>

#include <RadiumDB/DCL/DataControlLanguage.hpp>
#include <RadiumDB/DDL/DataDefinitionLanguage.hpp>
#include <RadiumDB/DML/DataModificationLanguage.hpp>

#include <RadiumDB/DDL/BasicTypes.hpp>
#include <RadiumDB/DCL/Document.hpp>

namespace RadiumDB {

class RadiumDB: public DCL::DataControlLanguage, 
                public DML::DataModificationLanguage,
                public DDL::DataDefinitionLanguage
{
public:
};

}

#endif // RDB_RADIUMDB_HPP
