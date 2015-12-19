cmake_minimum_required (VERSION 2.6)

SET(SOURCE
  System.cxx
)

SET(HEADERS
  System.h
  OS.h
  NullPtr.h
  pragmas.h
  System/String.h
  System/IO.h
  System.h
  System/DateTime.h
  System/Environment.h
  System/Exception.h
  System/Math.h
  System/Net.h
  System/Net/WebClient.h
  TimeSpan.h
)

add_library(cpp-net-framework ${SOURCE} ${HEADERS})

include_directories(../framework)

