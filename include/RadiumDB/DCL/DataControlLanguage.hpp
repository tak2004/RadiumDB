#ifndef RDB_DCL_DATACONTROLLANGUAGE_HPP
#define RDB_DCL_DATACONTROLLANGUAGE_HPP

#include <RadonFramework/Radon.hpp>
#include <RadiumDB/DCL/DocumentLocator.hpp>
#include <RadiumDB/DCL/DocumentReader.hpp>
#include <RadiumDB/DCL/DocumentWriter.hpp>
#include <RadiumDB/DCL/Document.hpp>

namespace RadiumDB { namespace DCL {

class DataControlLanguage
{
public:
    RF_Util::UUID CreateDocument();

    RF_Type::Bool Get(const RF_Util::UUID& Identifier, Document& CopyTo);

    RF_Type::Bool Delete(const RF_Util::UUID& Identifier);

    RF_Type::Bool Update(const Document& ReplaceBy);

    void SetDocumentWriter(RF_Mem::AutoPointer<DocumentWriter>& NewDocumentWriter);
    void SetDocumentReader(RF_Mem::AutoPointer<DocumentReader>& NewDocumentReader);
protected:
    RF_Mem::AutoPointer<DocumentLocator> m_Locator;
    RF_Mem::AutoPointer<DocumentWriter> m_Writer;
    RF_Mem::AutoPointer<DocumentReader> m_Reader;
};

} }

#endif // RDB_DCL_DATACONTROLLANGUAGE_HPP