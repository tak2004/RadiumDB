#include <RadonFramework/precompiled.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/TestSuite.hpp>
#include <RadonFramework/Diagnostics/Debugging/UnitTest/UnitTest.hpp>
#include <RadiumDB/RadiumDB.hpp>
#include <BinaryDocument/BinaryDocumentReader.hpp>
#include <BinaryDocument/BinaryDocumentWriter.hpp>

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
        RadiumDB::RadiumDB db;
        RF_Mem::AutoPointer<RadiumDB::DDL::Template> asset(new RadiumDB::DDL::Template);
        asset->Name("Asset"_rfs);
        asset->RegisterMember("tags"_rfs, "List"_rfs, "String"_rfs);
        asset->RegisterMember("sources"_rfs, "List"_rfs, "String"_rfs);
        asset->RegisterMember("location"_rfs, "String"_rfs);
        db.RegisterType(static_cast<RF_Mem::AutoPointer<RadiumDB::DDL::Type>>(asset));

        RF_Mem::AutoPointer<RadiumDB::DCL::DocumentReader> reader(new RadiumDB::BinaryDocumentReader);
        RF_Mem::AutoPointer<RadiumDB::DCL::DocumentWriter> writer(new RadiumDB::BinaryDocumentWriter);
        db.SetDocumentReader(reader);
        db.SetDocumentWriter(writer);

        RF_Mem::AutoPointer<RadiumDB::DCL::DocumentLocator> locator(new RadiumDB::DCL::DocumentLocator);
        locator->SetRootLocation(RF_Type::String("file://"));
        db.SetDocumentLocator(locator);

        RF_Util::UUID generatedAsset = db.CreateDocument();
        RadiumDB::DCL::Document requestedAsset;
        if(db.Get(generatedAsset, requestedAsset))
        {
            requestedAsset.SetType("Asset"_rfs);
            requestedAsset.SetStr("tags"_rfs)
            if(db.Update(requestedAsset))
            {
                db.Delete(generatedAsset);
            }
        }
        return true;
    }
};

DBTest DBTestInstance;