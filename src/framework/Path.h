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
