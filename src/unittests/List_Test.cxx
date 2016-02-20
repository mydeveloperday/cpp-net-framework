


#include "gtest/gtest.h"

#include "System.h"

using namespace System;

TEST(ListTest, Basic)
{
    List<String> myAL;

    EXPECT_EQ(0,myAL.Count());

    myAL.Add(String("Hello"));
    myAL.Add(String("World"));
    myAL.Add(String("!"));

    Console::WriteLine("myAL");

    EXPECT_EQ(3,myAL.Count());

    myAL.Clear();

    EXPECT_EQ(0,myAL.Count());

    myAL.Add(String("Hello"));

    EXPECT_EQ(1,myAL.Count());

    List<String> myList;

    myList.Add("World");
    myList.Add("London");

    myAL.AddRange(myList);

    EXPECT_EQ(3,myAL.Count());
    
    for(auto c : myAL){
        System::Console::WriteLine(c);
    }
}
