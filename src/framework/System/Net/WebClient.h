#ifndef _INCLUDED_SYSTEM_WEBCLIENT_H_
#define _INCLUDED_SYSTEM_WEBCLIENT_H_

#include <ctime>
#include <cstring>

#include <sys/types.h>

#ifdef _WIN32
#include <winsock.h>
#else
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#endif

#include "OS.h"
#include "System/String.h"
#include "System/Exception.h"
#include "TimeSpan.h"

#include "pragmas.h"

namespace System
{
    class InitNet
    {
    public:
        InitNet()
        {
#ifdef _WIN32
            WSADATA wsaData;
            WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif
        }
    };

    InitNet g_initNet;


    class WebClient
    {
    public:
        /// Constructor for DateTime
        WebClient()
        {
        }

        /// Download the contents of this web request
        String DownloadString(String address)
        {
            struct hostent * host = gethostbyname(address.str().c_str());

            if ( (host == nullptr) || (host->h_addr == nullptr)) 
            {
                throw System::SystemException("Cannot resolve address");
            }

            struct sockaddr_in client;
            memset(&client, 0, sizeof(client));
            client.sin_family = AF_INET;
            client.sin_port = htons( 80 );
            memcpy(&client.sin_addr, host->h_addr, host->h_length);

            int socketNum = socket(AF_INET, SOCK_STREAM, 0);

            if (socketNum < 0) {
                throw System::SystemException("Cannot create socket address");
            }

            if ( connect(socketNum, 
                         (struct sockaddr *)&client, 
                         sizeof(client)) < 0 ) 
            {
#ifdef _WIN32
                closesocket(socketNum);
#else
                close(socketNum);
#endif
                throw System::SystemException("Cannot connect");
            }

            String httpRequest;
            httpRequest= "GET / ";
            httpRequest += "HTTP/1.1\r\n";
            httpRequest += "Host: ";
            httpRequest += address;
            httpRequest += "\r\n";
            httpRequest += "\r\n\r\n";

            int httpRequestSize=httpRequest.Length();

            if (send(socketNum, httpRequest.str().c_str(), 
                     httpRequestSize, 0) != httpRequestSize) 
            {
                throw System::SystemException("Error sending request");
            }

            String httpResponse;

#ifdef _WIN32
            char data[4096];
            while (recv(socketNum, &data, 4096, 0)) {
                httpResponse += data;
            }
            closesocket(socketNum);
#else
            char data; 
            while ( read(socketNum, &data, 1) > 0 ) {
                httpResponse+=data;
            }
            close(socketNum);
#endif

            

            return httpResponse;
        }
    };
}

using namespace System;

#endif
