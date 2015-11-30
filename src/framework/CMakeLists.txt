cmake_minimum_required (VERSION 2.6)

SET(SOURCE
  System.cxx
)

SET(HEADERS
  System.h
  NetString.h
  OS.h
  System.IO.h
  System.h
)

add_library(cpp-net-framework ${SOURCE} ${HEADERS})

