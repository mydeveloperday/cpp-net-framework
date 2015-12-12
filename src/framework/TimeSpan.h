#ifndef _INCLUDED_SYSTEM_DATETIME_H_
#define _INCLUDED_SYSTEM_DATETIME_H_

#include <iostream>
#include <string>
#include <ctime>
#include <cstring>

#include "OS.h"
#include "NetString.h"
#include "Exception.h"

#include "pragmas.h"

namespace System
{
    class TimeSpan
    {
        double m_duration;
		
    public:
        TimeSpan()
        {
        }        
    };
}

using namespace System;

#endif
