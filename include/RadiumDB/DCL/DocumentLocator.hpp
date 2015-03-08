#ifndef RDB_DCL_DOCUMENTLOCATOR_HPP
#define RDB_DCL_DOCUMENTLOCATOR_HPP

#include <RadonFramework/Radon.hpp>

namespace RadiumDB { namespace DCL {

/*
* This is the standard document locator which translate UUID into URI's.
* Derive from this class to change the distribution behaviour of files.
**/
class DocumentLocator
{
public:
    virtual RF_IO::Uri Translate(const RF_Util::UUID& Identifier);
    virtual void SetRootLocation(const RF_IO::Uri& NewRootLocation);
protected:
    RF_IO::Uri m_RootLocation;
};

} }

#endif // RDB_DCL_DOCUMENTLOCATOR_HPP
