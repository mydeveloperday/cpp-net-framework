cmake_minimum_required (VERSION 2.8)

include_directories(../../framework)

add_executable(CSharpToCpp 
               main.cxx 
               driver.cxx
              )
			  
set (DEST ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE_INIT})
			  
target_link_libraries (cpp-net-framework)
