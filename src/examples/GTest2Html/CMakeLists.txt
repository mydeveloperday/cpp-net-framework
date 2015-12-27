cmake_minimum_required (VERSION 2.8)

include_directories(../..)
include_directories(../../framework)

add_executable(GTest2Html 
               main.cxx 
               driver.cxx
               gtest_out.txt
              )
			  
set (DEST ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE_INIT})
			  
file(COPY gtest_out.txt DESTINATION ${DEST})

target_link_libraries (GTest2Html cpp-net-framework)


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
