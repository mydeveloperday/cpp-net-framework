
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

