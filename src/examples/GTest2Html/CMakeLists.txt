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

target_link_libraries (cpp-net-framework)
