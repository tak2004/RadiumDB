#ifndef RDB_DCL_DOCUMENTWRITER_HPP
#define RDB_DCL_DOCUMENTWRITER_HPP

#include <RadonFramework/Radon.hpp>

namespace RadiumDB { namespace DCL {

class DocumentWriter
{
public:
    virtual RF_Type::Bool CreateEmpty(RF_IO::Uri& Location) {}
};

} }

#endif // RDB_DCL_DOCUMENTWRITER_HPP
