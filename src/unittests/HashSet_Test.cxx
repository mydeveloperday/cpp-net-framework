
#include "gtest/gtest.h"

#include "System.h"
#include "System/Collections/Generic.h"
#include "System/String.h"

using namespace System;

TEST(HashSetTests, Basic)
{
    HashSet<String> myDict;

    myDict.Add(String("Hello"));

    EXPECT_TRUE(myDict.Contains(String("Hello")));
    EXPECT_FALSE(myDict.Contains(String("World")));

    EXPECT_EQ(1, myDict.Count());

    myDict.Clear();

    EXPECT_EQ(0, myDict.Count());
}
