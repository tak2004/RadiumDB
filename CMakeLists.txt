cmake_minimum_required(VERSION 2.8.11)
project(RadiumDB)

include("Integrate.cmake")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${RadiumDB_SOURCE_DIR}/dist)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${RadiumDB_SOURCE_DIR}/dist)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${RadiumDB_SOURCE_DIR}/dist)

rcf_addlocation(RADONFRAMEWORK "git" "https://github.com/tak2004/RadonFramework.git")
Integrate(RADONFRAMEWORK "Radon framework" "RADONFRAMEWORK_HOME")

OPTION(RADIUMDB_BUILD_RESOURCETEST "Enable the resource test" OFF)

AddSourceDirectoryRecursive(sharedenginesrclist "src" "Source")
AddHeaderDirectoryRecursive(sharedenginehdrlist "include/RadiumDB" "Includes")
set(RADIUMDB_FILES ${sharedenginesrclist} ${sharedenginehdrlist})

option(RADIUMDB_ADD_JSON_DOCUMENTS "Add JSON document implementation." OFF)
if (RADIUMDB_ADD_JSON_DOCUMENTS)
	AddSourceDirectoryRecursive(sharedenginesrclist "modules/JSONDocument" "Source\\JSONDocument")
	AddHeaderDirectoryRecursive(sharedenginehdrlist "modules/JSONDocument" "Includes\\JSONDocument")
	set(RADIUMDB_FILES ${RADIUMDB_FILES} ${sharedenginesrclist} ${sharedenginehdrlist})
endif()

Generate(MODULE RADIUMDB RadiumDB "RadiumDB")
if (RADIUMDB_ADD_JSON_DOCUMENTS)
	AddPublicInclude(RADIUMDB "${RadiumDB_SOURCE_DIR}/modules")	
endif()
AddPublicInclude(RADIUMDB "${RadiumDB_SOURCE_DIR}/include")
AddDependency(RADIUMDB RadonFramework)
Finalize(RADIUMDB)

if(RADIUMDB_BUILD_RESOURCETEST)
	add_subdirectory(tests/ResourceTest)
endif()