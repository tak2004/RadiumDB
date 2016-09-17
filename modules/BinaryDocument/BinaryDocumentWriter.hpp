#ifndef RADIUMDB_BINARYDOCUMENTWRITER_HPP
#define RADIUMDB_BINARYDOCUMENTWRITER_HPP
#if _MSC_VER > 1000
#pragma once
#endif

#include <RadiumDB/DCL/DocumentWriter.hpp>

namespace RadiumDB {

class BinaryDocumentWriter : public DCL::DocumentWriter
{
public:
    virtual RF_Type::Bool CreateEmpty(RF_IO::Uri& Location);
};

}

#endif // RADIUMDB_BINARYDOCUMENTWRITER_HPP