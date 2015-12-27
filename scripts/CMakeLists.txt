configure_file(${CMAKE_CURRENT_SOURCE_DIR}/install_coverage.sh
    ${CMAKE_CURRENT_BINARY_DIR}/install_coverage.sh COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/finish_coverage.sh
    ${CMAKE_CURRENT_BINARY_DIR}/finish_coverage.sh COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/publish_doxygen.sh
    ${CMAKE_CURRENT_BINARY_DIR}/publish_doxygen.sh COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/push_doxygen.sh
    ${CMAKE_CURRENT_BINARY_DIR}/push_doxygen.sh COPYONLY)
