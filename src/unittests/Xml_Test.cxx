
#include "gtest/gtest.h"

#include "System.h"
#include "System/Xml.h"
#include "System/Collections/Generic.h"

using namespace System;

TEST(XmlTests, BasicTests)
{
    XmlDocument xml;
    
    String xmlstr = "<book ISBN='1-861001-57-5'>" \
                "<title>Pride And Prejudice</title>" \
                "<price>19.95</price>" \
                "</book>";

   
    List<XmlToken> toks = xml.LoadXmlParse(xmlstr);
    
    EXPECT_EQ(8,toks.Count());
    
    for(size_t i=0;i<toks.Count();i++)
    {
        System::Console::WriteLine(toks[i].ToString());
    }
    
    xml.LoadXml(xmlstr);
    
    EXPECT_TRUE(xml.HasChildNodes());
}
