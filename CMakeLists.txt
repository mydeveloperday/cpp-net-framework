cmake_minimum_required (VERSION 2.8)
project (cpp-net-framework)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -Wno-unused-function -Wno-variadic-macros -Werror")
endif()

if(${CMAKE_COMPILER_ID} MATCHES GNU AND $cpp-netframework)
    set_target_properties(StringTest PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -gp -fprofile-coverage -fprofile-args" LINK_FLAGS "-fprofile-arcs")
endif()

ENABLE_TESTING()
INCLUDE(CTest)

add_subdirectory(src)
add_subdirectory(scripts)

set(CTEST_TARGET_SYSTEM "Linux-Ubuntu-14.04-x64")
set(CTEST_MODEL         "Performance")

# add a target to generate API documentation with Doxygen
find_package(Doxygen)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)

add_custom_target(doc
    pwd
    ls -al
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM
)

