#include "gtest/gtest.h"

#include "System.h"

using namespace System;

TEST(DateTimeTest, BasicDateOperations)
{
    DateTime christmasDay(2015, 12, 25);

    EXPECT_EQ(25, christmasDay.Day());
    EXPECT_EQ(12, christmasDay.Month());
    EXPECT_EQ(2015, christmasDay.Year());
  
    DateTime boxingDay(2015, 12, 26);
 
    EXPECT_EQ(26, boxingDay.Day());
    EXPECT_EQ(12, boxingDay.Month());
    EXPECT_EQ(2015, boxingDay.Year());
 
    TimeSpan timeBetweenTurkey = boxingDay-christmasDay;

    EXPECT_EQ(1, timeBetweenTurkey.Days());
 
    TimeSpan interval(1, 15, 42, 45, 750);

    EXPECT_EQ(15,interval.Hours());
    EXPECT_EQ(39,interval.Days() * 24 + interval.Hours());
    EXPECT_EQ(42,interval.Minutes());
    EXPECT_EQ(45,interval.Seconds());
    EXPECT_EQ(750,interval.Milliseconds());
}

TEST(DateTimeTest, Ticks)
{
    DateTime centuryBegin(2001, 1, 1);
    DateTime currentDate(2007, 12, 14, 15, 23);

    int64_t elapsedTicks = currentDate.Ticks() - centuryBegin.Ticks();
    TimeSpan elapsedSpan(elapsedTicks);

    EXPECT_EQ(2193385800000000, elapsedTicks);

    EXPECT_EQ(2193385800000000U, elapsedSpan.Ticks());
    EXPECT_NEAR(2538.64, elapsedSpan.TotalDays(),0.1);
    EXPECT_NEAR(3655643.0, elapsedSpan.TotalMinutes(),0.1);
    EXPECT_NEAR(219338580.0, elapsedSpan.TotalSeconds(),0.1);
}

TEST(TimeSpanTests, TimeSpan)
{
    TimeSpan baseTimeSpan(1,12,15,16);

    EXPECT_EQ(12,baseTimeSpan.Hours());

    TimeSpan span1 = TimeSpan::FromDays(1.5);

    EXPECT_NEAR(1.5, span1.TotalDays(),0.1);
}

TEST(TimeSpanTests, TimeSpan2)
{
    TimeSpan baseTimeSpan(12,15,16);

    EXPECT_EQ(12,baseTimeSpan.Hours());
}
