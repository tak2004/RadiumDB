#ifndef RDB_MEMORYDOCUMENTREADER_HPP
#define RDB_MEMORYDOCUMENTREADER_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RadiumDB/DCL/DocumentReader.hpp>

namespace RadiumDB {

class MemoryDocumentReader: public DCL::DocumentReader
{
public:
    virtual RF_Type::Bool ReadFrom(const RF_IO::Uri& Location, DCL::Document& IntoDocument);
};

}

#endif // RDB_MEMORYDOCUMENTREADER_HPP