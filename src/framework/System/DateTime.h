<<<<<<< HEAD:src/framework/DateTime.h
#ifndef _INCLUDED_SYSTEM_DATETIME_H_
#define _INCLUDED_SYSTEM_DATETIME_H_

#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

#include "OS.h"
#include "NetString.h"
#include "Exception.h"

#include "pragmas.h"

namespace System
{
    class DateTime
    {
        std::time_t m_time;

    public:
        DateTime(int year, int month, int day)
        {
            struct tm timeinfo;
            std::memset(&timeinfo, 0, sizeof(tm));
            timeinfo.tm_year = year - 1900;
            timeinfo.tm_mon = month - 1;
            timeinfo.tm_mday = day;

            m_time = mktime(&timeinfo);
        }

        /// NOT a .NET Call
        DateTime(const std::time_t& t)
            : m_time(t)
        {
        }

        int Day() const
        {
            struct tm* rawtime;
            rawtime = localtime(&m_time);
            return rawtime->tm_mday;
        }

        int Month() const
        {
            struct tm* rawtime;
            rawtime = localtime(&m_time);
            return rawtime->tm_mon + 1;
        }

        int Year() const
        {
            struct tm* rawtime;
            rawtime = localtime(&m_time);
            return rawtime->tm_year + 1900;
        }

        static DateTime Now()
        {
            return DateTime(time(nullptr));
        }
    };
}

using namespace System;

#endif
=======
#ifndef _INCLUDED_SYSTEM_DATETIME_H_
#define _INCLUDED_SYSTEM_DATETIME_H_

#include <ctime>
#include <cstring>

#include "OS.h"
#include "System/String.h"
#include "System/Exception.h"

#include "pragmas.h"

namespace System
{
    class DateTime
    {
        std::time_t m_time;

    public:
        DateTime(int year, int month, int day)
        {
            struct tm timeinfo;
            std::memset(&timeinfo, 0, sizeof(tm));
            timeinfo.tm_year = year - 1900;
            timeinfo.tm_mon = month - 1;
            timeinfo.tm_mday = day;

            m_time = mktime(&timeinfo);
        }

        /// NOT a .NET Call
        DateTime(const std::time_t& t)
            : m_time(t)
        {
        }

        int Day() const
        {
            struct tm* rawtime;
            rawtime = localtime(&m_time);
            return rawtime->tm_mday;
        }

        int Month() const
        {
            struct tm* rawtime;
            rawtime = localtime(&m_time);
            return rawtime->tm_mon + 1;
        }

        int Year() const
        {
            struct tm* rawtime;
            rawtime = localtime(&m_time);
            return rawtime->tm_year + 1900;
        }

        static DateTime Now()
        {
            return DateTime(time(nullptr));
        }
    };
}

using namespace System;

#endif
>>>>>>> a30a7cc330fa54010280ba40246ca6e89193bffa:src/framework/System/DateTime.h
