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
    /// The TimeSpan class used to present a duration
    class TimeSpan
    {
        // seconds
        double m_duration;

    public:
        /// Constructor
        TimeSpan(int64_t ticks)
        {
            m_duration = static_cast<double>(ticks);
        }

        /// constrcutor from fractional seconds
        TimeSpan(double duration)
        {
            m_duration = duration;
        }

        /// constrcutor from hours minutes and seconds
        TimeSpan(int hours, int minutes, int seconds)
        {
            double t = 0.0;

            int ts = seconds + (60 * minutes) + (3600 * hours);

            double dts = static_cast<double>(ts);
            m_duration = (dts + t) * TIME_SCALE;
        }

        /// constrcutor from days, hours minutes and seconds
        TimeSpan(int days, int hours, int minutes, int seconds)
        {
            double t = 0.0;

            int ts =
                seconds + (60 * minutes) + (3600 * hours) + (24 * 3600) * days;

            double dts = static_cast<double>(ts);
            m_duration = (dts + t) * TIME_SCALE;
        }

        /// constrcutor from days, hours, minutes, seconds and milliseconds
        TimeSpan(
            int days, int hours, int minutes, int seconds, int milliseconds)
        {
            double t = ((static_cast<double>(milliseconds)) / 1000.0);

            int ts =
                seconds + (60 * minutes) + (3600 * hours) + (24 * 3600) * days;

            double dts = static_cast<double>(ts);
            m_duration = (dts + t) * TIME_SCALE;
        }

        /// get the number of days in the time span
        int Days()
        {
            return static_cast<int>(toSeconds(m_duration) / (3600 * 24));
        }

        /// get the number of hours in the time span
        int Hours()
        {
            return static_cast<int>(toSeconds(m_duration) / (3600)) -
                (Days() * 24);
        }

        /// get the number of minutes in the time span
        int Minutes()
        {
            return static_cast<int>(toSeconds(m_duration) / (60)) -
                (Days() * 24 * 60) - (Hours() * 60);
        }

        /// get the number of seconds in the time span
        int Seconds()
        {
            return static_cast<int>(toSeconds(m_duration)) -
                (Days() * 24 * 60 * 60) - (Hours() * 60 * 60) -
                (Minutes() * 60);
        }

        /// get the number of milliseconds in the time span
        int Milliseconds()
        {
            return static_cast<int>(static_cast<double>(toSeconds(m_duration) -
                                        (Math::Floor(toSeconds(m_duration)))) *
                1000.0);
        }

        /// get the total number of ticks
        uint64_t Ticks()
        {
            return static_cast<uint64_t>(m_duration);
        }

        /// get the total number of fractional days
        double TotalDays()
        {
            return static_cast<double>(toSeconds(m_duration) / (3600.0 * 24.0));
        }

        /// get the total number of fractional minutes
        double TotalMinutes()
        {
            return static_cast<double>(toSeconds(m_duration) / (60.0));
        }

        /// get the total number of fractional seconds
        double TotalSeconds()
        {
            return static_cast<double>(toSeconds(m_duration));
        }

        /// get the total number of fractional milliseconds
        double TotalMilliseconds()
        {
            return static_cast<double>(toMilliseconds(m_duration));
        }

        /// create a time span from fractional days
        static TimeSpan FromDays(double d)
        {
            TimeSpan t1(fromSeconds(d * 24.0 * 3600.0));
            return t1;
        }

        /// utility function to scale up and down seconds (NOT .NET Call)
        static double toSeconds(double d)
        {
            return d / TIME_SCALE;
        }

        /// utility function to scale up and down seconds (NOT .NET Call)
        static double fromSeconds(double d)
        {
            return d * TIME_SCALE;
        }

        /// utility function to scale up and down seconds (NOT .NET Call)
        static double toMilliseconds(double d)
        {
            return (1000.0 * d) / TIME_SCALE;
        }
    };
}

using namespace System;

#endif
