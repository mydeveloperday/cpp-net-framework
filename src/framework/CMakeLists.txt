cmake_minimum_required (VERSION 2.6)

SET(SOURCE
  System.cxx
  System/Object.cxx
  Path.cxx
  System/IO/FileInfo.cxx
  System/IO/StreamReader.cxx
  System/IO/File.cxx
)

SET(HEADERS
  System.h
  OS.h
  NullPtr.h
  pragmas.h
  System/String.h
  System/StringBuilder.h
  System/IO.h
  System/IO/FileInfo.h
  System/IO/StreamReader.h
  System/IO/StreamWriter.h
  System.h
  System/DateTime.h
  System/Environment.h
  System/Exception.h
  System/Math.h
  System/ArrayList.h
  System/Array.h
  System/Object.h
  System/Net.h
  System/Net/WebClient.h
  System/Collections/Generic/Dictionary.h
  System/Collections/Generic/List.h
  System/Collections/Generic/HashSet.h
  TimeSpan.h
  Path.h
)

add_library(cpp-net-framework ${SOURCE} ${HEADERS})

include_directories(../framework)

# visual studio magic
if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS /NODEFAULTLIB:\"msvcprtd.lib;MSVCRTD.lib\")

    FOREACH(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        if(${flag_var} MATCHES "/MD")
            string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
        endif(${flag_var} MATCHES "/MD")
    ENDFOREACH(flag_var)
endif()

