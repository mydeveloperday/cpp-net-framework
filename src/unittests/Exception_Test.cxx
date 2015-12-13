
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
      EXPECT_EQ(String("MyMessage"), e.what());
    }

    try {
      throw SystemException("MySystemMessage");
    }
    catch(Exception &e)
    {
      EXPECT_EQ(e.Message(),"MySystemMessage");
      EXPECT_EQ(String("MySystemMessage"),e.what());
    }

    try {
      throw NotImplementedException("MyNotImplementedMessage");
    }
    catch(Exception &e)
    {
      EXPECT_EQ(e.Message(),"MyNotImplementedMessage");
      EXPECT_EQ(String("MyNotImplementedMessage"),e.what());
    }
}

