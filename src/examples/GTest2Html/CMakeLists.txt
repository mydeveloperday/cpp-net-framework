cmake_minimum_required (VERSION 2.8)

#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

include_directories(../../framework)

add_executable(GTest2Html 
               main.cxx 
               driver.cxx
               gtest_out.txt
              )
			  
set (DEST ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_BUILD_TYPE_INIT})
			  
file(COPY gtest_out.txt DESTINATION ${DEST})

target_include_directories (cpp-net-framework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (cpp-net-framework)
