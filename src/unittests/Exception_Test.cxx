
#include "gtest/gtest.h"

#include "System.h"
#include "System/IO.h"

using namespace System;

TEST(ExceptionTest, Constructors)
{
    try {
      throw Exception("MyMessage");
    }
    catch(Exception &e)
    {
      EXPECT_EQ(e.Message(),"MyMessage");
    }

    try {
      throw SystemException("MyMessage");
    }
    catch(Exception &e)
    {
      EXPECT_EQ(e.Message(),"MyMessage");
    }

    try {
      throw NotImplementedException("MyMessage");
    }
    catch(Exception &e)
    {
      EXPECT_EQ(e.Message(),"MyMessage");
    }
}

