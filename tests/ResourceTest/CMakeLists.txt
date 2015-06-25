# enable json document support
set(RADIUMDB_ADD_JSON_DOCUMENTS ON CACHE BOOL "" FORCE)

AddSourceDirectoryRecursive(filelist "src" "Source")
CreatePrecompiledHeader(RADIUMDB_RESOURCETEST "precompiled.hpp" "src/precompiled.cpp" filelist)
set(RADIUMDB_RESOURCETEST_FILES ${filelist})
Generate(EXECUTABLE RADIUMDB_RESOURCETEST RDB_ResourceTest "RadiumDB")
target_include_directories(RDB_ResourceTest PRIVATE src/)
AddDependency(RADIUMDB_RESOURCETEST RadonFramework RadiumDB)
Finalize(RADIUMDB_RESOURCETEST)