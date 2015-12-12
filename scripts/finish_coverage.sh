#!/bin/bash

set -ev
cd ${TRAVIS_BUILD_DIR}
lcov --directory . --capture --output-file coverage.info
lcov --remove coverage.info 'src/googletest/*' '/src/unittests/*' '/usr/*' --output-file coverage.info
lcov --list coverage.info
coveralls-lcov --repo-token BaUcbfJ8J1gXICFozb2XkORNryx2FeQhV coverage.info


