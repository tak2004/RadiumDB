cmake_minimum_required(VERSION 2.8.11)
project(RadiumDB)

include("Integrate.cmake")

AddSourceDirectoryRecursive(sharedenginesrclist "src" "Source")
AddHeaderDirectoryRecursive(sharedenginehdrlist "include/RadiumDB" "Includes")
set(RADIUMDB_FILES ${sharedenginesrclist} ${sharedenginehdrlist})
Generate(MODULE RADIUMDB RadiumDB "Framework")
AddPublicInclude(RADIUMDB ${RadiumDB_SOURCE_DIR}/include/)
AddDependency(RADIUMDB RadonFramework)
Finalize(RADIUMDB)