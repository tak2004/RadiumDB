#include "BinaryDocument/BinaryDocumentReader.hpp"

namespace RadiumDB {

RF_Type::Bool BinaryDocumentReader::ReadFrom(const RF_IO::Uri& Location, DCL::Document& IntoDocument)
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