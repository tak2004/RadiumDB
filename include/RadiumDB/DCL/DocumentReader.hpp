#ifndef RDB_DCL_DOCUMENTREADER_HPP
#define RDB_DCL_DOCUMENTREADER_HPP

#include <RadonFramework/Radon.hpp>

namespace RadiumDB { namespace DCL {

class DocumentReader
{
public:
    virtual RF_Type::Bool ReadFrom(const RF_IO::Uri& Location, Document& IntoDocument) {}
};

} }

#endif // RDB_DCL_DOCUMENTREADER_HPP
