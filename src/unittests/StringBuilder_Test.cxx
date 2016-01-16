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

	EXPECT_EQ("ABCWorldHello",sb.ToString());

	EXPECT_EQ('C',sb[2]);
}
