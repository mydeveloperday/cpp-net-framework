<<<<<<< HEAD
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
  TimeSpan.h
)

add_library(cpp-net-framework ${SOURCE} ${HEADERS})

=======
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
)

add_library(cpp-net-framework ${SOURCE} ${HEADERS})

include_directories(../framework)

>>>>>>> a30a7cc330fa54010280ba40246ca6e89193bffa
