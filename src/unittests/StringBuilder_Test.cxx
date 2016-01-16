#include "gtest/gtest.h"

#include "System.h"

using namespace System;

TEST(StringBuilderTest, Creation)
{
    StringBuilder sb;
    String world("World");
    sb.Append("ABC");
    sb.Append(world);
    sb.Append("Hello");

    EXPECT_EQ("ABCWorldHello", sb.ToString());

    EXPECT_EQ('C', sb[2]);

    EXPECT_TRUE(Char::IsLetter('C'));
    EXPECT_TRUE(Char::IsLetter('c'));

    EXPECT_TRUE(Char::IsDigit('1'));
    EXPECT_TRUE(Char::IsLetterOrDigit('1'));
    EXPECT_TRUE(Char::IsLetterOrDigit('A'));

    EXPECT_TRUE(Char::IsWhiteSpace(' '));
    EXPECT_TRUE(Char::IsWhiteSpace('\t'));

    EXPECT_TRUE(Char::IsPunctuation('!'));
    EXPECT_TRUE(Char::IsPunctuation('.'));
    EXPECT_TRUE(Char::IsPunctuation(';'));
}
