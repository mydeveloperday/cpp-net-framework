
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

    EXPECT_EQ("HelloWorld", res.str());

    EXPECT_EQ("Hello/World", resb.str());

    EXPECT_EQ("HELLOWORLD", res.ToUpper().str());
    EXPECT_EQ("helloworld", res.ToLower().str());

    EXPECT_TRUE(res.Contains("Hello"));
    EXPECT_TRUE(res.Contains("World"));
    EXPECT_FALSE(res.Contains("Apples"));

    EXPECT_TRUE(res == "HelloWorld");
    EXPECT_FALSE(res == "Apples");
    EXPECT_FALSE(res != "HelloWorld");
    EXPECT_TRUE(res != "Applies");

    EXPECT_EQ(6, String("HelloWorld").LastIndexOf('o'));
    EXPECT_EQ(6, String("HelloWorld").LastIndexOf("or"));

    EXPECT_EQ(4, String("HelloWorld").IndexOf('o'));
    EXPECT_EQ(6, String("HelloWorld").IndexOf("or"));

    EXPECT_EQ("World", res.Substring(5));
    EXPECT_EQ("Wo", res.Substring(5, 2));

    EXPECT_EQ("HelloWorld", Concat("Hello", "World"));
}
