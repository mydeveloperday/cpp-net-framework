#!/bin/bash

echo "Running Install Coverage on " ${TRAVIS_OS_NAME}

if [[ ${TRAVIS_OK_NAME} = "linux" ]]
then
   echo "Installing Coverage Tools"
   set -ev
   cd ${TRAVIS_BUILD_DIR}
   wget http://ftp.de.debian.org/debian/pool/main/l/lcov/lcov_1.11.orig.tar.gz
   tar xf lcov_1.11.orig.tar.gz
   sudo make -C lcov-1.11/ install
   gem install coveralls-lcov
   lcov --version
   g++ --version
   lcov --directory . --zerocounters
else
   echo "Ignoring Coverage On Mac"
fi
