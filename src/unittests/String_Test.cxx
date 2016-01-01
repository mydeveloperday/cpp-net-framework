#include "gtest/gtest.h"

#include "System.h"

using namespace System;

TEST(StringTest, Creation)
{
    EXPECT_EQ(5, System::String("Hello").Length());

    EXPECT_EQ('e', System::String("Hello")[1]);

    String a = "Hello";
    String b = "World";
    String res = a + b;

    String resb = a + "/" + b;

    EXPECT_EQ("HelloWorld", res.str());

    EXPECT_EQ("Hello/World", resb.str());
    // EXPECT_EQ("Hello/World", static_cast<const char *>(resb));
}

TEST(StringTest, Case)
{
    String a = "Hello";
    String b = "World";
    String res = a + b;
    EXPECT_EQ("HELLOWORLD", res.ToUpper().str());
    EXPECT_EQ("helloworld", res.ToLower().str());
}

TEST(StringTest, Contains)
{
    String a = "Hello";
    String b = "World";
    String res = a + b;
    EXPECT_TRUE(res.Contains("Hello"));
    EXPECT_TRUE(res.Contains("World"));
    EXPECT_FALSE(res.Contains("Apples"));
}

TEST(StringTest, Operands)
{
    String a = "Hello";
    String b = "World";
    String res = a + b;
    EXPECT_TRUE(res == "HelloWorld");
    EXPECT_FALSE(res == "Apples");
    EXPECT_FALSE(res != "HelloWorld");
    EXPECT_TRUE(res != "Applies");
}

TEST(StringTest, Index)
{
    EXPECT_EQ(6, String("HelloWorld").LastIndexOf('o'));
    EXPECT_EQ(6, String("HelloWorld").LastIndexOf("or"));
    EXPECT_EQ(-1, String("HelloWorld").LastIndexOf("Ap"));

 
    EXPECT_EQ(4, String("HelloWorld").IndexOf('o'));
    EXPECT_EQ(6, String("HelloWorld").IndexOf("or"));
    EXPECT_EQ(-1, String("HelloWorld").IndexOf("Ap"));

    EXPECT_EQ(-1, String("HelloWorld").IndexOf('z'));
    EXPECT_EQ(-1, String("HelloWorld").LastIndexOf('z'));
}

TEST(StringTest, SubString)
{
    String a = "Hello";
    String b = "World";
    String res = a + b;
    EXPECT_EQ("World", res.Substring(5));
    EXPECT_EQ("Wo", res.Substring(5, 2));
}

TEST(StringTest, Concat)
{
    EXPECT_EQ("HelloWorld", Concat("Hello", "World"));
}

TEST(StringTest, StartsWith)
{
    EXPECT_TRUE(String("HelloWorld").StartsWith("Hello"));
    EXPECT_FALSE(String("HelloWorld").StartsWith("ello"));
    EXPECT_FALSE(String("HelloWorld").StartsWith("ello"));
    EXPECT_TRUE(String("HelloWorld").StartsWith("Hell"));
    EXPECT_TRUE(String("HelloWorld").StartsWith("Hell"));
    EXPECT_TRUE(String("HelloWorld").StartsWith("Hel"));
    EXPECT_TRUE(String("HelloWorld").StartsWith("He"));
    EXPECT_TRUE(String("HelloWorld").StartsWith("H"));
    EXPECT_FALSE(String("HelloWorld").StartsWith(""));
    EXPECT_TRUE(String("HelloWorld").StartsWith("Hello"));
    EXPECT_TRUE(String("HelloWorld").StartsWith("HelloW"));
    EXPECT_TRUE(String("HelloWorld").StartsWith("HelloWo"));
    EXPECT_TRUE(String("HelloWorld").StartsWith("HelloWor"));
    EXPECT_TRUE(String("HelloWorld").StartsWith("HelloWorl"));
    EXPECT_TRUE(String("HelloWorld").StartsWith("HelloWorld"));
    EXPECT_FALSE(String("HelloWorld").StartsWith("HelloWorldApples"));
}

TEST(StringTest, EndsWith)
{
    EXPECT_TRUE(String("HelloWorld").EndsWith("HelloWorld"));
    EXPECT_TRUE(String("HelloWorld").EndsWith("elloWorld"));
    EXPECT_TRUE(String("HelloWorld").EndsWith("lloWorld"));
    EXPECT_TRUE(String("HelloWorld").EndsWith("loWorld"));
    EXPECT_TRUE(String("HelloWorld").EndsWith("oWorld"));
    EXPECT_TRUE(String("HelloWorld").EndsWith("World"));
    EXPECT_TRUE(String("HelloWorld").EndsWith("orld"));
    EXPECT_TRUE(String("HelloWorld").EndsWith("rld"));
    EXPECT_TRUE(String("HelloWorld").EndsWith("ld"));
    EXPECT_TRUE(String("HelloWorld").EndsWith("d"));
    EXPECT_FALSE(String("HelloWorld").EndsWith(""));

    EXPECT_FALSE(String("HelloWorld").EndsWith("ApplesHelloWorld"));
}

TEST(StringTest, Replace)
{
    EXPECT_EQ(String("WorldWorld"),String("HelloWorld").Replace("Hello","World"));
    EXPECT_EQ(String("HelloHello"),String("HelloWorld").Replace("World","Hello"));
    EXPECT_EQ(String("HelloWorld"),String("HelloWorld").Replace("Apples","Oranges"));
    EXPECT_EQ(String("HelloCruelWorld"),String("HelloWorld").Replace("World","CruelWorld"));
    EXPECT_EQ(String("HelliWirld"),String("HelloWorld").Replace("o","i"));

    String ns = "using System.Collections.Generic;";
    EXPECT_EQ("using System.Collections.Generic;",ns);

    ns = ns.Replace("using ","#include \"");
    EXPECT_EQ("#include \"System.Collections.Generic;",ns);

    ns = ns.Replace(".","/");
    ns = ns.Replace(";",".h\"");
    ns = ns.Replace("",".h\"");

    EXPECT_EQ("#include \"System/Collections/Generic.h\"",ns);
}

TEST(StringTest, Trim)
{
    EXPECT_EQ(String("Hello"),String("  Hello").Trim());
    EXPECT_EQ(String("Hello"),String("Hello  ").Trim());
    EXPECT_EQ(String("Hello"),String("Hello").Trim());
    EXPECT_EQ(String("Hello"),String("   Hello   ").Trim());

    EXPECT_EQ(String("Hello"),String("  Hello").TrimStart());
    EXPECT_EQ(String("Hello  "),String("Hello  ").TrimStart());
    EXPECT_EQ(String("Hello"),String("Hello").TrimStart());
    EXPECT_EQ(String("Hello   "),String("   Hello   ").TrimStart());

    EXPECT_EQ(String("  Hello"),String("  Hello").TrimEnd());
    EXPECT_EQ(String("Hello"),String("Hello  ").TrimEnd());
    EXPECT_EQ(String("Hello"),String("Hello").TrimEnd());
    EXPECT_EQ(String("   Hello"),String("   Hello   ").TrimEnd());
    EXPECT_EQ(String(""),String("").Trim());
    EXPECT_EQ(String(""),String("").TrimEnd());
    EXPECT_EQ(String(""),String("").TrimStart());
}

TEST(StringTest, NullOrEmpty)
{
    EXPECT_FALSE(String::IsNullOrEmpty(String("Hello")));
    EXPECT_TRUE(String::IsNullOrEmpty(String("")));
    
    String myString="Hello";
    EXPECT_FALSE(String::IsNullOrEmpty(myString));
    
    myString.Clear();
    
    EXPECT_TRUE(String::IsNullOrEmpty(myString));
}

TEST(StringTest, Equals)
{
    EXPECT_TRUE(String("Hello").Equals("Hello"));
    EXPECT_FALSE(String("Hello").Equals("hello"));
    EXPECT_TRUE(String("Hello").Equals("Hello",OrdinalIgnoreCase));
    EXPECT_TRUE(String("Hello").Equals("hello",OrdinalIgnoreCase));
}
