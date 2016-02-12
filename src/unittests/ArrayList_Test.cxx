
#include "gtest/gtest.h"

#include "System.h"

using namespace System;

TEST(ArrayList, Basic)
{
    ArrayList myAL;

    EXPECT_EQ(0,myAL.Length());

    myAL.Add(String("Hello"));
    myAL.Add(String("World"));
    myAL.Add(String("!"));

    Console::WriteLine("myAL");

    EXPECT_EQ(3,myAL.Length());

    myAL.Clear();

    EXPECT_EQ(0,myAL.Length());

    myAL.Add(String("Hello"));

    EXPECT_EQ(1,myAL.Length());

    List<String> myList;

    myList.Add("World");
    myList.Add("London");

    myAL.AddRange(myList);

    EXPECT_EQ(3,myAL.Length());
}
