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
  DateTime.h
  Environment.h
  Exception.h
  NullPtr.h
  pragmas.h
)

add_library(cpp-net-framework ${SOURCE} ${HEADERS})

