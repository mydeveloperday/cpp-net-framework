cmake_minimum_required (VERSION 2.8)

include_directories(../../framework)

add_executable(CSharpToCpp 
               main.cxx 
               driver.cxx
              )
			  
set (DEST ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE_INIT})
			  
target_link_libraries (CSharpToCpp cpp-net-framework )

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