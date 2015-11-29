#ifndef _INCLUDED_SYSTEM_STRING_H_
#define _INCLUDED_SYSTEM_STRING_H_

#include <iostream>
#include <string>
#include <vector>

#pragma warning(disable: 4100)
#pragma warning(disable: 4505)

namespace System
{
    class string
    {
        std::string m_str;

        public:
        string()
        {}

        string(const char *str):
            m_str(str)
        {}

        std::string str() const{
            return m_str;
        }
    };
}


using namespace System;

#endif
