cmake_minimum_required (VERSION 3.1.0)
project (cpp-net-framework)

ENABLE_TESTING()
INCLUDE(CTest)

add_subdirectory(src)

set(CTEST_TARGET_SYSTEM "Linux-Ubuntu-14.04-x64")
set(CTEST_MODEL         "Performance")
