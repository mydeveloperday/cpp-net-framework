
#include "gtest/gtest.h"

#include "System.h"
#include "System/Net.h"

using namespace System;

TEST(WebClientTest, Download)
{
    {
        String address = "my.cdash.org";

        WebClient client;
        String reply = client.DownloadString(address);

        EXPECT_TRUE(reply.Contains("html"));
    }

    {
        String address = "unknown.abc.def";

        WebClient client;
        try {
            String reply = client.DownloadString(address);
        }
        catch (Exception) {
            EXPECT_TRUE(true);
        }
    }

    {
        String address = "github.com";

        WebClient client;
        try {
            String reply = client.DownloadString(address);
        }
        catch (Exception) {
            EXPECT_TRUE(true);
        }
    }
}
