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

    long elapsedTicks = currentDate.Ticks() - centuryBegin.Ticks();
    TimeSpan elapsedSpan(elapsedTicks);

    //EXPECT_EQ(2193385800000000, elapsedTicks);

    /*
    Console::WriteLine("Elapsed from the beginning of the century to {0:f}:",
        currentDate);
    Console::WriteLine("   {0:N0} nanoseconds", elapsedTicks * 100);
    Console::WriteLine("   {0:N0} ticks", elapsedTicks);
    Console::WriteLine("   {0:N2} seconds", elapsedSpan.TotalSeconds);
    Console::WriteLine("   {0:N2} minutes", elapsedSpan.TotalMinutes);
    Console::WriteLine("   {0:N0} days, {1} hours, {2} minutes, {3} seconds",
        elapsedSpan.Days(), elapsedSpan.Hours(),
        elapsedSpan.Minutes(), elapsedSpan.Seconds*();
    */
    // If run on December 14, 2007, at 15:23, this example displays the
    // following output to the console:
    //    Elapsed from the beginning of the century to Friday, December 14, 2007 3:23 PM:
    //          219,338,580,000,000,000 nanoseconds
    //          2,193,385,800,000,000 ticks
    //          219,338,580.00 seconds
    //          3,655,643.00 minutes
    //          2,538 days, 15 hours, 23 minutes, 0 seconds
}
