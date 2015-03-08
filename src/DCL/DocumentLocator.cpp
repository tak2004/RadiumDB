#include "RadiumDB/DCL/DocumentLocator.hpp"

namespace RadiumDB { namespace DCL {

RF_IO::Uri DocumentLocator::Translate(const RF_Util::UUID& Identifier)
{
    RF_IO::Uri result(m_RootLocation.OriginalString()+"/"+Identifier.ToString());
    return result;
}

void DocumentLocator::SetRootLocation(const RF_IO::Uri& NewRootLocation)
{
    m_RootLocation = NewRootLocation;
}

} }