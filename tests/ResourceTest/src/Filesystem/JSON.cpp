#include <RadonFramework/precompiled.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/TestSuite.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/UnitTest.hpp>

class JSONTest:public RF_Test::TestSuite
{
public:
    JSONTest()
    :TestSuite("RadiumDB::JSONTest")
    {
        AddTest(MakeDelegate(this, &JSONTest::Write), "JSONTest::Write", "write json file");
    }

    RF_Type::Bool Write()
    {
        return true;
    }
};

JSONTest JSONTestInstance;