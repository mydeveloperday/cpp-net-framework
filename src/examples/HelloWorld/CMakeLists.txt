cmake_minimum_required (VERSION 2.8.11)

include_directories(../../framework)

add_executable(HelloWorld main.cxx driver.cxx)

target_include_directories (cpp-net-framework PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (cpp-net-framework)
