#ifndef RDB_JSONDOCUMENTREADER_HPP
#define RDB_JSONDOCUMENTREADER_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RadiumDB/DCL/DocumentReader.hpp>

namespace RadiumDB {

class JSONDocumentReader: public DCL::DocumentReader
{
public:
    virtual RF_Type::Bool ReadFrom(const RF_IO::Uri& Location, DCL::Document& IntoDocument);
};

}

#endif // RDB_JSONDOCUMENTREADER_HPP