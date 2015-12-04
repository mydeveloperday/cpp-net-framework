
#include "gtest/gtest.h"

#include "System.h"
#include "System/IO.h"

using namespace System;

TEST(FileInfoTest, BasicFileOperations)
{
    FileInfo info("myfile.txt");

    EXPECT_FALSE(info.Exists());

    EXPECT_TRUE(info.FullName().Contains("myfile.txt"));

    std::string filesName = info.Name().str().c_str();
    EXPECT_EQ(filesName, "myfile.txt");
    EXPECT_TRUE(info.Name().Equals("myfile.txt"));

    EXPECT_TRUE(info.Extension().Equals(".txt"));
}

TEST(EnvironmentTests, BasicEnvironmentOperations)
{
    EXPECT_TRUE(Environment::CurrentDirectory().Contains("unittests"));
}
