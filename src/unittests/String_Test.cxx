
#include "gtest/gtest.h"

#include "framework/System.h"

using namespace System;

TEST(StringTest, Creation)
{
    EXPECT_EQ(5, System::String("Hello").Length());

    EXPECT_EQ('e', System::String("Hello")[1]);

    String a = "Hello";
    String b = "World";
    String res = a + b;

    String resb = a + "/" + b;


    EXPECT_EQ("HelloWorld",res.str());

    EXPECT_EQ("Hello/World", resb.str());

    EXPECT_EQ("HELLOWORLD", res.ToUpper().str());
    EXPECT_EQ("helloworld", res.ToLower().str());
}

