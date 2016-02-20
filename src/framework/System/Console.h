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
            std::cout << str << "\n";
        }

        /// function fro writing a single stirng to the terminal
        /// followed by a new line
        static void WriteLine(const System::String& str)
        {
            WriteLine(str.str().c_str());
        }
        
        /// function to support {0} arguments passing
        static void WriteLine(const System::String& str,const Object &a)
        {
            String s;
            s = s.Format(str,a);
            WriteLine(s.str().c_str());
        }
        
        /// function with const char * format
        static void WriteLine(const char *str,const Object &a)
        {
            String s;
            s = s.Format(str,a);
            WriteLine(s.str().c_str());
        }

        /// write function which does not print a new line
        static void Write(const char* str)
        {
            std::cout << str;
        }

        /// write function which does not print a new line
        static void Write(const System::String& str)
        {
            Write(str.str().c_str());
        }
    }
}

using namespace System;

#endif
