
#include "gtest/gtest.h"

#include "System.h"
#include "System/Net.h"

using namespace System;

TEST(WebClientTest, Download)
{
    String address="my.cdash.org";

    WebClient client;
    String reply = client.DownloadString (address);

    Console::WriteLine (reply);

    EXPECT_TRUE(reply.Contains("html"));
}
