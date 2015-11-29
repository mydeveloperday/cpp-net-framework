#ifndef _INCLUDED_SYSTEM_H_
#define _INCLUDED_SYSTEM_H_

#include <iostream>
#include <string>
#include <vector>

#include "NetString.h"

#pragma warning(disable: 4100)
#pragma warning(disable: 4505)

namespace System
{
    namespace Console
    {
        static void WriteLine(const char *str)
        {
            std::cout << str << std::endl;
        }

        static void WriteLine(const System::string &str)
        {
            std::cout << str.str() << std::endl;
        }
    };
}

using namespace System;

#endif
