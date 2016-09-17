#ifndef RDB_COMPRESSEDDOCUMENTREADER_HPP
#define RDB_COMPRESSEDDOCUMENTREADER_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RadiumDB/DCL/DocumentReader.hpp>

namespace RadiumDB {

class CompressedDocumentReader: public DCL::DocumentReader
{
public:
    virtual RF_Type::Bool ReadFrom(const RF_IO::Uri& Location, DCL::Document& IntoDocument);
};

}

#endif // RDB_COMPRESSEDDOCUMENTREADER_HPP