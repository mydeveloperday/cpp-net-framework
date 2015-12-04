cmake_minimum_required (VERSION 2.8.7)

include( CTest )

IF(MSVC)
SET(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:\"msvcprtd.lib;MSVCRTD.lib\")

FOREACH(flag_var
    CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
    CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    if(${flag_var} MATCHES "/MD")
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
    endif(${flag_var} MATCHES "/MD")
ENDFOREACH(flag_var)
ENDIF()

IF(CMAKE_COMPILER_IS_GNUCC)
SET(CMAKE_CXX_FLAGS "-g -O0 -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
ENDIF()

include_directories(../framework)
include_directories(../googletest/include)

enable_testing()

add_executable(System_Test 
               String_Test.cxx
               FileInfo_Test.cxx
               DateTime_Test.cxx
               Stream_Test.cxx
              )

IF(GNU)
target_link_libraries (System_Test cpp-net-framework gtest gtest_main gcov)
ELSE()
target_link_libraries (System_Test cpp-net-framework gtest gtest_main)
ENDIF()

add_test( System_Test System_Test )
