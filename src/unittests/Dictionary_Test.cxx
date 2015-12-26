
#include "gtest/gtest.h"

#include "System.h"
#include "System/Collections/Generic.h"
#include "String.h"

using namespace System;

TEST(DictionaryTests, Basic)
{
    Dictionary<String,String> myDict;

    myDict.Add(String("Hello"),String("World"));
    
    EXPECT_EQ(String("World"),myDict[String("Hello")]);
    
    EXPECT_TRUE(myDict.ContainsKey(String("Hello")));
    EXPECT_FALSE(myDict.ContainsKey(String("Work")));
    
    EXPECT_FALSE(myDict.ContainsValue(String("Hello")));
    EXPECT_TRUE(myDict.ContainsValue(String("World")));

    EXPECT_EQ(1,myDict.Count());
    
    myDict.Clear();
    
    EXPECT_EQ(0,myDict.Count());
    
    myDict.Add(String("My"),String("World"));
    myDict.Add(String("You"),String("Apple"));
    
    myDict.Remove(String("You"));
    
    EXPECT_TRUE(myDict.ContainsKey(String("My")));
    EXPECT_FALSE(myDict.ContainsKey(String("You")));
}
