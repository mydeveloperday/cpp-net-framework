# cpp-net-framework
An experimental .NET Framework for C++

[![Build Status](https://travis-ci.org/mydeveloperday/cpp-net-framework.svg?branch=master)](https://travis-ci.org/mydeveloperday/cpp-net-framework)

## Introduction

cpp-net-framework is an experimental C++ implementation of the .NET Framework, its purpose is to bring the power of the .NET Framework for use within C++ applications. 

## Build instructions

To build the example programmes

```
mkdir build
cd build
cmake -G "Visual Studio 12 2013" ../src
devenv cpp-net-framework.sln
```

## Initial Goals of cpp-net-framework

Here is a rough list of initial goals

1) To develop a library that would allow the speed and efficiency of development that comes from the use of the .NET Framework  
2) To mimic where possible the .NET Framework API  
3) To allow .NET framework and STL to interop directly  
4) It should be functional first before fast (do what is needed to get the API worry about speed later)  
5) Be cross platform  
6) Be compilable on a number of different build platforms  
7) Be test driven  

## What it is not

1) Not to mimic C# as a language  
2) Its not managed C++  

## How we'll implement these goals

Additional libraries should be kept to a minimum, the source tree contains googletest to encourage test driven development and if possible we should 
limit the external dependencies (for now) purely from the aspect of being able to easily build on multiple platforms. 

The library will use STL underneath. Platform specifics should be pushed down to an OS layer (to be implemented), to keep #ifdef in the main code at a minimum


## Follow the discussion

This idea for a c++ .net framework came out from my blog

https://mydeveloperday.wordpress.com/2015/11/27/making-a-c-net-framework-part-1/
https://mydeveloperday.wordpress.com/2015/11/30/making-a-c-net-framework-part-2/

## About MyDeveloper Day

Follow the my development stories at our blog

https://mydeveloperday.wordpress.com/
