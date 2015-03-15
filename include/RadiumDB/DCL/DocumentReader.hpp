#ifndef RDB_DCL_DOCUMENTREADER_HPP
#define RDB_DCL_DOCUMENTREADER_HPP

#include <RadonFramework/Radon.hpp>

namespace RadiumDB { namespace DCL {

class Document;

class DocumentReader
{
public:
    virtual RF_Type::Bool ReadFrom(const RF_IO::Uri& Location, Document& IntoDocument) { return false; }
};

} }

#endif // RDB_DCL_DOCUMENTREADER_HPP
