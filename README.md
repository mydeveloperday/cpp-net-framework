# cpp-net-framework

An experimental .NET Framework for C++

[![Build Status](https://travis-ci.org/mydeveloperday/cpp-net-framework.svg?branch=master)](https://travis-ci.org/mydeveloperday/cpp-net-framework) 
<a href="https://ci.appveyor.com/project/mydeveloperday/cpp-net-framework">
  <img alt="AppVeyor Scan Build Status"
       src="https://ci.appveyor.com/api/projects/status/32r7s2skrgm9ubva?svg=true"/>
</a>
<a href="https://scan.coverity.com/projects/mydeveloperday-cpp-net-framework">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/7174/badge.svg"/>
</a>
[![Coverage Status](https://coveralls.io/repos/github/mydeveloperday/cpp-net-framework/badge.svg?branch=master)](https://coveralls.io/github/mydeveloperday/cpp-net-framework?branch=master)



## Introduction

cpp-net-framework is an experimental C++ implementation of the .NET Framework, its purpose is to bring the power of the .NET Framework for use within C++ applications. 

## Build instructions

To build the example programmes

```
mkdir build
cd build
cmake -G "Visual Studio 12 2013" ../cpp-net-framework
devenv cpp-net-framework.sln
```

## Initial Goals of cpp-net-framework

Here is a rough list of initial goals

1) To develop a library that would allow the speed and efficiency of development that comes from the use of the .NET Framework  
2) To mimic where possible the .NET Framework API  
3) To allow .NET framework and STL to interop directly  
4) It should be functional first before fast (do what is needed to get the API worry about speed later)  
5) Be cross platform  
6) Be test driven  
7) To use open source software services to build good stable code

## What it is not

1) Not to mimic C# as a language  
2) Its not managed C++  

## How we'll implement these goals

Additional libraries should be kept to a minimum, the source tree contains googletest to encourage test driven development and if possible we should 
limit the external dependencies (for now) purely from the aspect of being able to easily build on multiple platforms. 

The library will use STL underneath. Platform specifics should be pushed down to an OS layer (to be implemented), to keep #ifdef in the main code at a minimum

See what needs to be done 
http://www.microsoft.com/en-IE/download/details.aspx?id=19341


## Follow the discussion

This idea for a c++ .net framework came out from my blog

https://mydeveloperday.wordpress.com/2015/11/27/making-a-c-net-framework-part-1/
https://mydeveloperday.wordpress.com/2015/11/30/making-a-c-net-framework-part-2/

Talk about this repository

[![Join the chat at https://gitter.im/mydeveloperday/cpp-net-framework](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/mydeveloperday/cpp-net-framework?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)


## About MyDeveloper Day

Follow the my development stories at our blog

https://mydeveloperday.wordpress.com/

This or link back to here
http://http://mydeveloperday.github.io/cpp-net-framework/
http://http://mydeveloperday.github.io/cpp-net-framework/doc/html/index.html
