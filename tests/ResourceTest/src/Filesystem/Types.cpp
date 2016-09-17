#include <RadonFramework/precompiled.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/TestSuite.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/UnitTest.hpp>

class TypesTest:public RF_Test::TestSuite
{
public:
    TypesTest()
    :TestSuite("RadiumDB::TypesTest"_rfs)
    {}
};

TypesTest TypesTestInstance;