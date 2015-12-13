configure_file(${CMAKE_CURRENT_SOURCE_DIR}/install_coverage.sh
    ${CMAKE_CURRENT_BINARY_DIR}/install_coverage.sh COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/finish_coverage.sh
    ${CMAKE_CURRENT_BINARY_DIR}/finish_coverage.sh COPYONLY)
