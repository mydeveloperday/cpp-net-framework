cmake_minimum_required (VERSION 2.8.7)

IF(WIN32)
SET(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:\"msvcprtd.lib;MSVCRTD.lib\")

FOREACH(flag_var
    CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
    CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    if(${flag_var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endif(${flag_var} MATCHES "/MD")
ENDFOREACH(flag_var)
ENDIF()

include_directories(../)
include_directories(../googletest/include)

add_executable(System_Test 
               String_Test.cxx
               FileInfo_Test.cxx
               DateTime_Test.cxx
               Stream_Test.cxx
              )

target_link_libraries (System_Test cpp-net-framework gtest gtest_main)

add_test( System_Test System_Test )
