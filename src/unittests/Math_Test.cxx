
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

TEST(MathTest, Abs)
{
    EXPECT_EQ(123, Math::Abs(-123));
    EXPECT_EQ(123.6, Math::Abs(-123.6));
    EXPECT_EQ(123, Math::Abs(123));
    EXPECT_EQ(123.6, Math::Abs(123.6));
}

TEST(MathTest, Round)
{
    EXPECT_EQ(124, Math::Round(123.6));
    EXPECT_EQ(123, Math::Round(123.4));
}

TEST(MathTest, Sign)
{
    EXPECT_EQ(-1, Math::Sign(-123));
    EXPECT_EQ(-1, Math::Sign(-123.4));

    EXPECT_EQ(1, Math::Sign(123));
    EXPECT_EQ(1, Math::Sign(123.4));
}

TEST(MathTest, Truncate)
{
    EXPECT_EQ(-123, Math::Truncate(-123.4));
    EXPECT_EQ(123, Math::Truncate(123.4));

    EXPECT_EQ(-123, Math::Truncate(-123.9));
    EXPECT_EQ(123, Math::Truncate(123.9));
}

TEST(MathTest, Ceiling)
{
    EXPECT_EQ(-7, Math::Ceiling(-7.1));
    EXPECT_EQ(-7, Math::Ceiling(-7.6));
    EXPECT_EQ(0, Math::Ceiling(-0.12));
    EXPECT_EQ(1, Math::Ceiling(0.12));
    EXPECT_EQ(8, Math::Ceiling(7.03));
    EXPECT_EQ(8, Math::Ceiling(7.64));
}

TEST(MathTest, Floor)
{
    EXPECT_EQ(123, Math::Floor(123.4));
    EXPECT_EQ(123, Math::Floor(123.5));
    EXPECT_EQ(123, Math::Floor(123.6));

    EXPECT_EQ(-1, Math::Floor(-0.12));
    EXPECT_EQ(0, Math::Floor(0.12));
    EXPECT_EQ(-8, Math::Floor(-7.1));
    EXPECT_EQ(-8, Math::Floor(-7.6));
    EXPECT_EQ(7, Math::Floor(7.03));
    EXPECT_EQ(7, Math::Floor(7.64));
}
