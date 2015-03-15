#ifndef RADIUMDB_JSONDOCUMENTWRITER_HPP
#define RADIUMDB_JSONDOCUMENTWRITER_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RadiumDB/DCL/DocumentWriter.hpp>

namespace RadiumDB {

class JSONDocumentWriter : public DCL::DocumentWriter
{
public:
    virtual RF_Type::Bool CreateEmpty(RF_IO::Uri& Location);
};

}

#endif // RADIUMDB_JSONDOCUMENTWRITER_HPP