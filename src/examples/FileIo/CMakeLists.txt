cmake_minimum_required (VERSION 2.8)

include_directories(../../framework)

add_executable(FileIo main.cxx driver.cxx)

target_link_libraries (cpp-net-framework)
