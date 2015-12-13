#ifndef _INCLUDED_SYSTEM_CONSOLE_H_
#define _INCLUDED_SYSTEM_CONSOLE_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "System/String.h"
#include "OS.h"
#include "System/Exception.h"
#include "System/DateTime.h"
#include "System/Environment.h"

#include "pragmas.h"

namespace System
{
    namespace Console
    {
        static void WriteLine(const char* str)
        {
            std::cout << str << std::endl;
        }

        static void WriteLine(const System::String& str)
        {
            std::cout << str.str() << std::endl;
        }
    }
}

using namespace System;

#endif
