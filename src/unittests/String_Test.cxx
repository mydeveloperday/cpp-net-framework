

#include "gtest/gtest.h"

#include "framework/System.h"

using namespace System;

TEST(StringTest, Creation)
{
    EXPECT_EQ(5, System::string("Hello").Length());
}

