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

    try {
        StreamReader sr("nonexistant_file.txt");
        sr.ReadLine();
    }
    catch (FileNotFoundException&) {
    }
}

TEST(EnvironmentTests, BasicEnvironmentOperations)
{
    System::Console::WriteLine(Environment::CurrentDirectory());
    EXPECT_TRUE(Environment::CurrentDirectory().Contains("unittests"));
}

TEST(EnvironmentTests, Extensions)
{
    EXPECT_EQ(FileInfo("myfile.txt").Extension(), ".txt");
    EXPECT_EQ(FileInfo("myfile.xlsx").Extension(), ".xlsx");
    EXPECT_EQ(FileInfo("myfile").Extension(), "");
}

TEST(EnvironmentTests, Name)
{
    EXPECT_EQ(FileInfo("myfile.txt").Name(), "myfile.txt");
    EXPECT_EQ(FileInfo("abc/myfile.txt").Name(), "myfile.txt");
    EXPECT_EQ(FileInfo("abc\\myfile.txt").Name(), "myfile.txt");
}

TEST(EnvironmentTests, Console)
{
    System::Console::WriteLine("Hello");
    System::Console::WriteLine(String("Hello"));
    System::Console::Write("Hello");
    System::Console::Write(String("Hello"));
}
