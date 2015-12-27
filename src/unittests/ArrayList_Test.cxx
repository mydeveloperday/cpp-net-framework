
#include "gtest/gtest.h"

#include "System.h"

using namespace System;

TEST(ArrayList, Basic)
{
    ArrayList myAL;

    myAL.Add(String("Hello"));
    myAL.Add(String("World"));
    myAL.Add(String("!"));

    Console::WriteLine("myAL");
}
