#include "gtest/gtest.h"

#include "System.h"
#include "System/IO.h"

using namespace System;

TEST(DirectoryTest, BasicFileOperations)
{
    Directory::CreateDirectory("ABC");

    DirectoryInfo info("ABC");
    EXPECT_TRUE(info.Exists());
    Directory::Delete("ABC");
    EXPECT_FALSE(info.Exists());
}
