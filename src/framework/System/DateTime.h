#ifndef _INCLUDED_SYSTEM_DATETIME_H_
#define _INCLUDED_SYSTEM_DATETIME_H_

#include <ctime>
#include <cstring>

#include "OS.h"
#include "System/String.h"
#include "System/Exception.h"
#include "TimeSpan.h"

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

        DateTime(int year, int month, int day, int hours, int minutes)
        {
            struct tm timeinfo;
            std::memset(&timeinfo, 0, sizeof(tm));
            timeinfo.tm_year = year - 1900;
            timeinfo.tm_mon = month - 1;
            timeinfo.tm_mday = day;
            timeinfo.tm_hour = hours;
            timeinfo.tm_min = minutes;

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

        int64_t Ticks() const{
            int64_t tick = static_cast<int64_t>(m_time) * static_cast<int64_t>(TIME_SCALE);
            return tick;
        }

    };

    inline TimeSpan operator-(const DateTime& a, const DateTime& b)
    {
        int64_t ticks = a.Ticks() - b.Ticks();

        TimeSpan ts(ticks);
        return ts;
    }
}

using namespace System;

#endif
