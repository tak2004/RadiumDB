#include <RadonFramework/precompiled.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/TestSuite.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/UnitTest.hpp>
#include <RadiumDB/RadiumDB.hpp>

class DBTest:public RF_Test::TestSuite
{
public:
    DBTest()
    :TestSuite("RadiumDB::DBTest"_rfs)
    {
        AddTest(MakeDelegate(this, &DBTest::Write), "DBTest::Write"_rfs, "write json file"_rfs);
    }

    RF_Type::Bool Write()
    {
        RF_Mem::AutoPointer<RadiumDB::DDL::Template> asset(new RadiumDB::DDL::Template);
        asset->Name("Asset"_rfs);
        asset->RegisterMember("tags"_rfs, "List"_rfs, "String"_rfs);
        asset->RegisterMember("sources"_rfs, "List"_rfs, "String"_rfs);
        asset->RegisterMember("location"_rfs, "String"_rfs);
        DBMS.RegisterType(static_cast<RF_Mem::AutoPointer<RadiumDB::DDL::Type>>(asset));

        RF_Mem::AutoPointer<RadiumDB::DCL::DocumentWriter> JSONWriter(new RadiumDB::JSONDocumentWriter);
        RF_Mem::AutoPointer<RadiumDB::DCL::DocumentReader> JSONReader(new RadiumDB::JSONDocumentReader);

        DBMS.SetDocumentWriter(JSONWriter);
        DBMS.SetDocumentReader(JSONReader);

        RF_Util::UUID generatedAsset = DBMS.CreateDocument();
        RadiumDB::DCL::Document requestedAsset;
        if(DBMS.Get(generatedAsset, requestedAsset))
        {
            if(DBMS.Update(requestedAsset))
            {
                DBMS.Delete(generatedAsset);
            }
        }
        return true;
    }
};

DBTest DBTestInstance;