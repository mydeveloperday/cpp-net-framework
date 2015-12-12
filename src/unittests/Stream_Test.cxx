<<<<<<< HEAD

#include "gtest/gtest.h"

#include "framework/System.h"
#include "framework/System.IO.h"

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
      while(!sr.EndOfStream()){
        String s = sr.ReadLine();
        input += s;
      }
      sr.Dispose();
    }

    EXPECT_EQ("Hello World",input);

    EXPECT_TRUE(info.Exists());
    info.Delete();
    EXPECT_FALSE(info.Exists());
}

=======

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
      while(!sr.EndOfStream()){
        String s = sr.ReadLine();
        input += s;
      }
      sr.Dispose();
    }

    EXPECT_EQ("Hello World",input);

    EXPECT_TRUE(info.Exists());
    info.Delete();
    EXPECT_FALSE(info.Exists());
}

TEST(StreamTest, NonExistantFiles)
{
    try {
      StreamReader sr("NonExistantFile.txt");
    }
    catch(Exception &e)
    {
      EXPECT_FALSE(String::IsNullOrEmpty(e.Message()));
      EXPECT_TRUE(true);
    }

    try {
        StreamReader sr("");
    }
    catch (Exception &e)
    {
        EXPECT_FALSE(String::IsNullOrEmpty(e.Message()));
        EXPECT_TRUE(true);
    }
}

>>>>>>> a30a7cc330fa54010280ba40246ca6e89193bffa
