cmake_minimum_required(VERSION 2.8.11)
project(RadiumDB)

include("Integrate.cmake")

AddSourceDirectoryRecursive(sharedenginesrclist "src" "Source")
AddHeaderDirectoryRecursive(sharedenginehdrlist "include/RadiumDB" "Includes")
set(RADIUMDB_FILES ${sharedenginesrclist} ${sharedenginehdrlist})

option(RADIUMDB_ADD_JSON_DOCUMENTS "Add JSON document implementation." OFF)
if (RADIUMDB_ADD_JSON_DOCUMENTS)
	AddSourceDirectoryRecursive(sharedenginesrclist "modules/JSONDocument" "Source\\JSONDocument")
	AddHeaderDirectoryRecursive(sharedenginehdrlist "modules/JSONDocument" "Includes\\JSONDocument")
	set(RADIUMDB_FILES ${RADIUMDB_FILES} ${sharedenginesrclist} ${sharedenginehdrlist})
endif()

Generate(MODULE RADIUMDB RadiumDB "Framework")
if (RADIUMDB_ADD_JSON_DOCUMENTS)
	AddPublicInclude(RADIUMDB "${RadiumDB_SOURCE_DIR}/modules")	
endif()
AddPublicInclude(RADIUMDB "${RadiumDB_SOURCE_DIR}/include")
AddDependency(RADIUMDB RadonFramework)
Finalize(RADIUMDB)