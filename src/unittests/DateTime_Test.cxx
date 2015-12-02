
#include "gtest/gtest.h"

#include "framework/System.h"

using namespace System;

TEST(DateTimeTest, BasicDateOperations)
{
    DateTime time(2015, 12, 25);

    EXPECT_EQ(25, time.Day());
    EXPECT_EQ(12, time.Month());
    EXPECT_EQ(2015, time.Year());
}
