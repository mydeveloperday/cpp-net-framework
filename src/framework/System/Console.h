<<<<<<< HEAD:src/framework/Console.h
#ifndef _INCLUDED_SYSTEM_CONSOLE_H_
#define _INCLUDED_SYSTEM_CONSOLE_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "NetString.h"
#include "OS.h"
#include "Exception.h"
#include "DateTime.h"
#include "Environment.h"

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
=======
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
>>>>>>> a30a7cc330fa54010280ba40246ca6e89193bffa:src/framework/System/Console.h
