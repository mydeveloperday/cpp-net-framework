#ifndef _INCLUDED_SYSTEM_TIMESPAN_H_
#define _INCLUDED_SYSTEM_TIMESPAN_H_

#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

#include "OS.h"
#include "String.h"
#include "System/Exception.h"
#include "System/Math.h"

#include "pragmas.h"

namespace System
{
    class TimeSpan
    {
        // seconds
        double m_duration;

    public:
        TimeSpan(long ticks)
        {
            m_duration = static_cast<double>(ticks);
        }

        TimeSpan(int days,int hours,int minutes,int seconds,int milliseconds)
        {
            double t= ((static_cast<double>(milliseconds)) / 1000.0);

            int ts = seconds + (60 * minutes) + (3600 * hours) + (24 * 3600)*days;

            double dts = static_cast<double>(ts);
            m_duration = dts + t;
        }

        int Days()
        {
            return static_cast<int>(m_duration/(3600 * 24));
        }

        int Hours()
        {
            return static_cast<int>(m_duration / (3600)) - (Days()*24);
        }

        int Minutes()
        {
            return static_cast<int>(m_duration / (60)) - (Days() * 24 * 60) - (Hours() * 60);
        }

        int Seconds()
        {
            return static_cast<int>(m_duration) - (Days() * 24 * 60 *60) - (Hours() * 60 *60) - (Minutes()*60);
        }

        int Milliseconds()
        {
            return static_cast<int>(static_cast<double>(m_duration - (Math::Floor(m_duration)))*1000.0);
        }
    };
}

using namespace System;

#endif
