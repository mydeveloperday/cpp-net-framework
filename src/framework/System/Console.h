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
    /// Console class
    namespace Console
    {
        /// function fro writing a single stirng to the terminal 
        /// followed by a new line
        static void WriteLine(const char* str)
        {
            std::cout << str << std::endl;
        }

        /// function fro writing a single stirng to the terminal 
        /// followed by a new line
        static void WriteLine(const System::String& str)
        {
            std::cout << str.str() << std::endl;
        }
    }
}

using namespace System;

#endif
