<<<<<<< HEAD
#ifndef _INCLUDED_SYSTEM_PATH_H_
#define _INCLUDED_SYSTEM_PATH_H_

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
    class Path
    {
    public:
        static System::String Combine(System::String a, System::String b)
        {
            String res = a + PATH_SEPARATOR + b;
            return res;
        }
    };
}

using namespace System;

#endif
=======
#ifndef _INCLUDED_SYSTEM_PATH_H_
#define _INCLUDED_SYSTEM_PATH_H_

#include "System/String.h"
#include "OS.h"

#include "System/Exception.h"
#include "System/DateTime.h"
#include "System/Environment.h"

#include "pragmas.h"

namespace System
{
    class Path
    {
    public:
        static System::String Combine(System::String a, System::String b)
        {
            String res = a + PATH_SEPARATOR + b;
            return res;
        }
    };
}

using namespace System;

#endif
>>>>>>> a30a7cc330fa54010280ba40246ca6e89193bffa
