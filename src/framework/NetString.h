#ifndef _INCLUDED_SYSTEM_STRING_H_
#define _INCLUDED_SYSTEM_STRING_H_

#include <iostream>
#include <string>
#include <vector>

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

        size_t Length() const {
            return m_str.size();
        }

        const char operator[](int pos)
        {
            return m_str[pos];
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
