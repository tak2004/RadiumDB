#include <RadonFramework/precompiled.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/TestSuite.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/UnitTest.hpp>
#include <RadiumDB/RadiumDB.hpp>
#include <JSONDocument/JSONDocumentWriter.hpp>

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
        RadiumDB::RadiumDB db;

        RF_Mem::AutoPointer<RadiumDB::DCL::DocumentWriter> jsonWriter(new RadiumDB::JSONDocumentWriter);
        db.SetDocumentWriter(jsonWriter);

        RF_Mem::AutoPointer<RadiumDB::DDL::Template> asset(new RadiumDB::DDL::Template);
        asset->Name("Asset");
        asset->RegisterMember("tags", "List", "String");
        asset->RegisterMember("sources", "List", "String");
        asset->RegisterMember("location", "String");
        db.RegisterType(static_cast<RF_Mem::AutoPointer<RadiumDB::DDL::Type> >(asset));

        // create an instance of Asset type and fill it with data
        RadiumDB::DCL::Document assetInstance;
        assetInstance.SetType("Asset");
        assetInstance.SetStr("location", "/shaders/static");
        assetInstance.SetStr("sources[]", "/shaders/static.json");
        assetInstance.SetStr("sources[]", "/shaders/static.vert");
        assetInstance.SetStr("sources[]", "/shaders/static.frag");
        assetInstance.SetStr("tags[]", "Shader");
        db.CreateDocument(assetInstance);

        // Change type to a newer version which is not registered.
        // All upcoming access commands will define the new type and will be
        // registered with the Update call.
        // The DocumentWriter decides if the old member will be saved or not.
        assetInstance.SetType("Asset_v1");
        assetInstance.SetStr("uri", assetInstance.GetStr("location"));
        // take over the sources and tag data from old type version
        assetInstance.SetStr("sources[]");
        assetInstance.SetStr("tags[]");
        db.Update(assetInstance);
        
        return true;
    }
};

JSONTest JSONTestInstance;