#include "BinaryDocument/BinaryDocumentWriter.hpp"

namespace RadiumDB {

RF_Type::Bool BinaryDocumentWriter::CreateEmpty(RF_IO::Uri& Location)
{
    RF_Type::Bool result = true;
    auto& protocol = RF_IO::ProtocolServiceLocator::Find(Location.Scheme());
    if(!RF_IO::ProtocolServiceLocator::IsNullService(protocol))
    {
        auto* stream = protocol.GenerateInterface(Location);
        if(stream)
        {
            protocol.FreeInterface(Location);
            result = true;
        }
    }
    return result;
}

}