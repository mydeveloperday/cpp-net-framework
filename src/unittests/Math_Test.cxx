
#include "gtest/gtest.h"

#include "System.h"


using namespace System;

TEST(MathTest, MaxMin)
{
    EXPECT_EQ(2, Math::Max(1,2));
    EXPECT_EQ(2, Math::Max(2,1));
    EXPECT_EQ(1, Math::Min(1,2));
    EXPECT_EQ(1, Math::Min(2,1));

    EXPECT_EQ(2, Math::Max(-2,2));
    EXPECT_EQ(-2, Math::Min(-2,2));

    EXPECT_EQ(0, Math::Max(0,0));
    EXPECT_EQ(1, Math::Max(1,1));

    EXPECT_EQ(2.0, Math::Max(1.0,2.0));
    EXPECT_EQ(2.0, Math::Max(2.0,1.0));
    EXPECT_EQ(1.0, Math::Min(1.0,2.0));
    EXPECT_EQ(1.0, Math::Min(2.0,1.0));

    EXPECT_EQ(2.0, Math::Max(-2.0,2.0));
    EXPECT_EQ(-2.0, Math::Min(-2.0,2.0));

    EXPECT_EQ(0.0, Math::Max(0.0,0.0));
    EXPECT_EQ(1.0, Math::Max(1.0,1.0));
}
