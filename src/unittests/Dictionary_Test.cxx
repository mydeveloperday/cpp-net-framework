
#include "gtest/gtest.h"

#include "System.h"
#include "System/Collections/Generic.h"

using namespace System;

TEST(DictionaryTests, Basic)
{
    Dictionary<String,String> myDict;

    myDict.Add(String("Hello"),String("World"));
    
    EXPECT_EQ(String("World"),myDict[String("Hello")]);
    
    EXPECT_TRUE(myDict.ContainsKey(String("Hello")));
    EXPECT_FALSE(myDict.ContainsKey(String("Work")));
}