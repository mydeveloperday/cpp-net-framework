#ifndef _INCLUDED_SYSTEM_H_
#define _INCLUDED_SYSTEM_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "NetString.h"
#include "OS.h"
#include "Exception.h"
#include "DateTime.h"

#include "pragmas.h"

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

    class Environment
    {
    public:
        static System::String CurrentDirectory()
        {
            // TODO move this centrally
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

#endif
