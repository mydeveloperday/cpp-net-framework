#ifndef _INCLUDED_SYSTEM_H_
#define _INCLUDED_SYSTEM_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "NetString.h"
#include "OS.h"
#include "Exception.h"

#pragma warning(disable: 4100)
#pragma warning(disable: 4505)

// localtime TODO replace with secure call
#pragma warning(push)
#pragma warning(disable: 4996)

namespace System
{
    namespace Console
    {
        static void WriteLine(const char *str)
        {
            std::cout << str << std::endl;
        }

        static void WriteLine(const System::String &str)
        {
            std::cout << str.str() << std::endl;
        }
    };

    template <class T>
    class List
    {
        std::vector<T> m_vec;
    public:
        List()
        {
        }

        int Count() const {
            return static_cast<int>(m_vec.size());
        }

        const T& operator[](int index) const {
            return m_vec[index];
        }
    };

    template <class T>
    class Array
    {
        std::vector<T> m_vec;
    public:
        Array()
        {}

        int Length() const {
            return static_cast<int>(m_vec.size());
        }

        const T& operator[](int index) const {
            return m_vec[index];
        }

        // private not part of .NET Framework
        void Add(const T& item)
        {
            m_vec.push_back(item);
        }
    };

    class DateTime
    {
        std::time_t m_time;

    public:
        DateTime(int year,int month,int day)
        {
            struct tm timeinfo;
            memset(&timeinfo, 0, sizeof(tm));
            timeinfo.tm_year = year - 1900;
            timeinfo.tm_mon = month -1;
            timeinfo.tm_mday = day;

            m_time = mktime(&timeinfo);
        }

        /// NOT a .NET Call
        DateTime(const std::time_t &t):
            m_time(t)
        {
        }

        int Day() const {
            struct tm *rawtime;
            rawtime = localtime(&m_time);
            return rawtime->tm_mday;
        }

        int Month() const {
            struct tm *rawtime;
            rawtime = localtime(&m_time);
            return rawtime->tm_mon+1;
        }

        int Year() const {
            struct tm *rawtime;
            rawtime =localtime(&m_time);
            return rawtime->tm_year+1900;
        }

        static DateTime Now()
        {
            return DateTime(time(nullptr));
        }
    };

    class Environment
    {
    public:
        static System::String CurrentDirectory()
        {
            char buffer[1024];

            // TODO this should be made platform independent
            if (_getcwd(buffer, sizeof(buffer))) {
                return System::String(buffer);
            }
            return System::String("");
        }
    };

    class Path
    {
    public:
        static System::String Combine(System::String a, System::String b)
        {
            String res = a + "\\" + b;
            return res;
        }
    };
    
}

using namespace System;

#pragma warning(pop)

#endif
