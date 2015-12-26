cmake_minimum_required (VERSION 2.8.7)


# enable CTest unit test runner

include( CTest )
enable_testing()

# add the framework libraries and google test
include_directories(../framework)
include_directories(../googletest/include)

# visual studio magic
if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:\"msvcprtd.lib;MSVCRTD.lib\")

    FOREACH(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        if(${flag_var} MATCHES "/MD")
            string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
        endif(${flag_var} MATCHES "/MD")
    ENDFOREACH(flag_var)
endif()

# turn on test coverage on gcc
if(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "-g -O0 -W -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "-g -O0 -W -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
endif()

# add my test
add_test( System_Test System_Test )

# the actual test executable and its sources
add_executable(System_Test 
               String_Test.cxx
               FileInfo_Test.cxx
               DateTime_Test.cxx
               Stream_Test.cxx
               Math_Test.cxx
               Exception_Test.cxx
               Internals_Test.cxx
               WebClient_Test.cxx
               ArrayList_Test.cxx
			   Dictionary_Test.cxx
              )

# alter the link line of gcc to include coverage library
if(CMAKE_COMPILER_IS_GNUCC)
    target_link_libraries (System_Test cpp-net-framework gtest gtest_main gcov)
else()
if(MSVC)
    target_link_libraries (System_Test cpp-net-framework gtest gtest_main ws2_32.lib)
else()
    target_link_libraries (System_Test cpp-net-framework gtest gtest_main )
endif()
endif()
