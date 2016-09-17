#include <RadonFramework/precompiled.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/TestSuite.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/UnitTest.hpp>
#include <RadiumDB/RadiumDB.hpp>
#include <JSONDocument/JSONDocumentWriter.hpp>

class JSONTest:public RF_Test::TestSuite
{
public:
    JSONTest()
    :TestSuite("RadiumDB::JSONTest"_rfs)
    {
        AddTest(MakeDelegate(this, &JSONTest::Write), "JSONTest::Write"_rfs, "write json file"_rfs);
    }

    RF_Type::Bool Write()
    {
        RadiumDB::RadiumDB db;

        RF_Mem::AutoPointer<RadiumDB::DCL::DocumentWriter> jsonWriter(new RadiumDB::JSONDocumentWriter);
        db.SetDocumentWriter(jsonWriter);

        RF_Mem::AutoPointer<RadiumDB::DDL::Template> asset(new RadiumDB::DDL::Template);
        asset->Name("Asset"_rfs);
        asset->RegisterMember("tags"_rfs, "List"_rfs, "String"_rfs);
        asset->RegisterMember("sources"_rfs, "List"_rfs, "String"_rfs);
        asset->RegisterMember("location"_rfs, "String"_rfs);
        db.RegisterType(static_cast<RF_Mem::AutoPointer<RadiumDB::DDL::Type> >(asset));

        // create an instance of Asset type and fill it with data
        RadiumDB::DCL::Document assetInstance;
        assetInstance.SetType("Asset"_rfs);
        assetInstance.SetStr("location"_rfs, "/shaders/static"_rfs);
        assetInstance.SetStr("sources[]"_rfs, "/shaders/static.json"_rfs);
        assetInstance.SetStr("sources[]"_rfs, "/shaders/static.vert"_rfs);
        assetInstance.SetStr("sources[]"_rfs, "/shaders/static.frag"_rfs);
        assetInstance.SetStr("tags[]"_rfs, "Shader"_rfs);
        db.CreateDocument(assetInstance);

        // Change type to a newer version which is not registered.
        // All upcoming access commands will define the new type and will be
        // registered with the Update call.
        // The DocumentWriter decides if the old member will be saved or not.
        assetInstance.SetType("Asset_v1"_rfs);
        assetInstance.SetStr("uri"_rfs, assetInstance.GetStr("location"_rfs));
        // take over the sources and tag data from old type version
        assetInstance.SetStr("sources[]"_rfs);
        assetInstance.SetStr("tags[]"_rfs);
        db.Update(assetInstance);
        
        return true;
    }
};

JSONTest JSONTestInstance;