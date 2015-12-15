#ifndef _INCLUDED_SYSTEM_TIMESPAN_H_
#define _INCLUDED_SYSTEM_TIMESPAN_H_

#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

#include "OS.h"
#include "System/String.h"
#include "System/Exception.h"
#include "System/Math.h"

#include "pragmas.h"

#define TIME_SCALE 10000000.0

namespace System
{
    class TimeSpan
    {
        // seconds
        double m_duration;

    public:
        TimeSpan(int64_t ticks)
        {
            m_duration = static_cast<double>(ticks);
        }

        TimeSpan(int hours,int minutes,int seconds)
        {
            double t= 0.0;

            int ts = seconds + (60 * minutes) + (3600 * hours);

            double dts = static_cast<double>(ts);
            m_duration = (dts + t)*TIME_SCALE;
        }

        TimeSpan(int days,int hours,int minutes,int seconds)
        {
            double t= 0.0;

            int ts = seconds + (60 * minutes) + (3600 * hours) + (24 * 3600)*days;

            double dts = static_cast<double>(ts);
            m_duration = (dts + t)*TIME_SCALE;
        }

        TimeSpan(int days,int hours,int minutes,int seconds,int milliseconds)
        {
            double t= ((static_cast<double>(milliseconds)) / 1000.0);

            int ts = seconds + (60 * minutes) + (3600 * hours) + (24 * 3600)*days;

            double dts = static_cast<double>(ts);
            m_duration = (dts + t)*TIME_SCALE;
        }


        int Days()
        {
            return static_cast<int>(toSeconds(m_duration)/(3600 * 24));
        }

        int Hours()
        {
            return static_cast<int>(toSeconds(m_duration) / (3600)) - (Days()*24);
        }

        int Minutes()
        {
            return static_cast<int>(toSeconds(m_duration) / (60)) - (Days() * 24 * 60) - (Hours() * 60);
        }

        int Seconds()
        {
            return static_cast<int>(toSeconds(m_duration)) - (Days() * 24 * 60 *60) - (Hours() * 60 *60) - (Minutes()*60);
        }

        int Milliseconds()
        {
            return static_cast<int>(static_cast<double>(toSeconds(m_duration) - (Math::Floor(toSeconds(m_duration))))*1000.0);
        }

        uint64_t Ticks()
        {
            return m_duration;
        }

        double TotalDays()
        {
            return static_cast<double>(toSeconds(m_duration)/(3600.0 * 24.0));
        }

        double TotalMinutes()
        {
            return static_cast<double>(toSeconds(m_duration) / (60.0));
        }

        double TotalSeconds()
        {
            return static_cast<double>(toSeconds(m_duration));
        }

        double TotalMilliseconds()
        {
            return static_cast<double>(toMilliseconds(m_duration));
        }

        static TimeSpan FromDays(double d)
        {
            TimeSpan t1(fromSeconds(d*24.0*3600.0));
            return t1;
        }

        static double toSeconds(double d)
        {
            return d / TIME_SCALE;
        }

        static double fromSeconds(double d)
        {
            return d * TIME_SCALE;
        }

        static double toMilliseconds(double d)
        {
            return (1000.0*d) / TIME_SCALE;
        }
    };
}

using namespace System;

#endif
