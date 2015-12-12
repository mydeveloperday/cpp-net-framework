<<<<<<< HEAD

#include "gtest/gtest.h"

#include "framework/System.h"

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
    
    EXPECT_EQ(1,timeBetweenTurkey.Days())
    
    TimeSpan interval = new TimeSpan(1, 15, 42, 45, 750); 
    
    EXPECT_EQ(15,interval.Hours());
    EXPECT_EQ(39,interval.Days() * 24 + interval.Hours());
    EXPECT_EQ(42,interval.Minutes());
    EXPECT_EQ(45,interval.Seconds());
    EXPECT_EQ(750,interval.Milliseconds());
}
=======

#include "gtest/gtest.h"

#include "System.h"

using namespace System;

TEST(DateTimeTest, BasicDateOperations)
{
    DateTime time(2015, 12, 25);

    EXPECT_EQ(25, time.Day());
    EXPECT_EQ(12, time.Month());
    EXPECT_EQ(2015, time.Year());
}
>>>>>>> a30a7cc330fa54010280ba40246ca6e89193bffa
