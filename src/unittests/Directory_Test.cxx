#include "gtest/gtest.h"

#include "System.h"
#include "System/IO.h"

using namespace System;

TEST(DirectoryTest, BasicFileOperations)
{
    Directory::CreateDirectory("ABC");
    Directory::Delete("ABC");
}
