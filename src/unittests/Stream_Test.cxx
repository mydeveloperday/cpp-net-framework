#include "gtest/gtest.h"

#include "System.h"
#include "System/IO.h"

using namespace System;

TEST(StreamTest, BasicStreamOperations)
{
    FileInfo info("myfile.txt");
    EXPECT_FALSE(info.Exists());

    StreamWriter sw(info.Name());
    {
        sw.WriteLine("Hello World");
        sw.Dispose();
    }

    EXPECT_TRUE(info.Exists());

    String input;
    StreamReader sr(info.Name());
    {
        while (!sr.EndOfStream()) {
            String s = sr.ReadLine();
            input += s;
        }
        sr.Dispose();
    }

    EXPECT_EQ("Hello World", input);

    EXPECT_TRUE(info.Exists());
    info.Delete();
    EXPECT_FALSE(info.Exists());
}

TEST(StreamTest, NonExistantFiles)
{
    try {
        StreamReader sr("NonExistantFile.txt");
    }
    catch (Exception& e) {
        EXPECT_FALSE(String::IsNullOrEmpty(e.Message()));
        EXPECT_TRUE(true);
    }

    try {
        StreamReader sr("");
    }
    catch (Exception& e) {
        EXPECT_FALSE(String::IsNullOrEmpty(e.Message()));
        EXPECT_TRUE(true);
    }
}

TEST(StreamTest, ReadToEndTest)
{
    FileInfo info("totalFile.txt");
    EXPECT_FALSE(info.Exists());

    String pears="Pears";
    StreamWriter sw(info.Name());
    {
        sw.WriteLine("Apples");
        sw.WriteLine("Orangles");
        sw.WriteLine("Any Fruit but not {0} because I don't like them ",pears);
        sw.Dispose();
    }

    EXPECT_TRUE(info.Exists());

    String input;
    StreamReader sr(info.Name());
    {
        input = sr.ReadToEnd();
        sr.Dispose();
    }

    EXPECT_TRUE(input.Contains("Pears"));

    EXPECT_TRUE(info.Exists());
    info.Delete();
    EXPECT_FALSE(info.Exists());
}
