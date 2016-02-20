#include "gtest/gtest.h"

#include "System.h"
#include "System/IO.h"

using namespace System;

TEST(DirectoryTest, BasicFileOperations)
{
    Directory::CreateDirectory("ABC");

    DirectoryInfo info("ABC");
    EXPECT_TRUE(info.Exists());
    
    Array<FileInfo> files = info.GetFiles();
    
    // I assume this is "." and ".."
    EXPECT_EQ(2,files.Length());
    
    Directory::Delete("ABC");
    EXPECT_FALSE(info.Exists());

    EXPECT_EQ(info.Name(),"ABC");
  
}
