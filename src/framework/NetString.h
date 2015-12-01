#ifndef _INCLUDED_SYSTEM_STRING_H_
#define _INCLUDED_SYSTEM_STRING_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

#pragma warning(disable: 4100)
#pragma warning(disable: 4505)

namespace System
{
    class String
    {
        std::string m_str;

        public:
        String()
        {}

        String(const char *str):
            m_str(str)
        {}

        // NOT .NET call
        std::string str() const{
            return m_str;
        }

        // NOT .NET call
        const std::string& operator()(std::string&) const
        {
            return str();
        }

        // NOT .NET call
        const char* operator()(const char *) const
        {
            return str().c_str();
        }

        size_t Length() const {
            return m_str.size();
        }

        const char operator[](int pos)
        {
            return m_str[pos];
        }

        String& operator+=(char c)
        {
            std::string newstring = (*this).str() + c;
            m_str = newstring;
            return (*this);
        }

        String ToUpper() const
        {
            String s;
            for (auto c : m_str) {
                s += toupper(c);
            }
            return s;
        }

        String ToLower() const
        {
            String s;
            for (auto c : m_str) {
                s += tolower(c);
            }
            return s;
        }
    };

    inline String operator + (const String &a, const String &b)
    {
        std::string m_res = a.str();
        m_res += b.str();
        return String(m_res.c_str());
    }
}

typedef System::String string;


using namespace System;

#endif
