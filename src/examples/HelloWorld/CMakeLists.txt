cmake_minimum_required (VERSION 2.6)

include_directories(../../framework)

add_executable(HelloWorld main.cxx driver.cxx)

target_link_libraries (cpp-net-framework)
