#include "RadiumDB/DCL/DataControlLanguage.hpp"
#include "RadiumDB/DCL/Document.hpp"

namespace RadiumDB { namespace DCL {

RF_Util::UUID DataControlLanguage::CreateDocument()
{
    RF_Util::UUID newID;
    RF_IO::Uri location;
    do
    {
        newID = RF_Util::UUID::SecureRandomUUID();
        location = m_Locator->Translate(newID);
        
    } while(m_Writer->CreateEmpty(location) == false);

    return newID;
}

RF_Type::Bool DataControlLanguage::Get(const RF_Util::UUID& Identifier,
                                       Document& CopyTo)
{
    RF_IO::Uri location = m_Locator->Translate(Identifier);
    return m_Reader->ReadFrom(location, CopyTo);
}

RF_Type::Bool DataControlLanguage::Delete(const RF_Util::UUID& Identifier)
{
    RF_IO::Uri location = m_Locator->Translate(Identifier);
    RF_IO::File file;
    file.SetLocation(location);
    return file.Delete();
}

RF_Type::Bool DataControlLanguage::Update(const Document& ReplaceBy)
{
    return false;
}

void DataControlLanguage::SetDocumentWriter(RF_Mem::AutoPointer<DocumentWriter>& NewDocumentWriter)
{
    m_Writer = NewDocumentWriter;
}

void DataControlLanguage::SetDocumentReader(RF_Mem::AutoPointer<DocumentReader>& NewDocumentReader)
{
    m_Reader = NewDocumentReader;
}

} }