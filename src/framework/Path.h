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
