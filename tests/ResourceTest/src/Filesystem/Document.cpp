#include <RadonFramework/precompiled.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/TestSuite.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/UnitTest.hpp>

class DocumentTest:public RF_Test::TestSuite
{
public:
    DocumentTest()
    :TestSuite("RadiumDB::DocumentTest"_rfs)
    {
    }
};

DocumentTest DocumentTestInstance;