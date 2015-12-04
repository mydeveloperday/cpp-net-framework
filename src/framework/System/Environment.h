#ifndef _INCLUDED_SYSTEM_ENVIRONMENT_H_
#define _INCLUDED_SYSTEM_ENVIRONMENT_H_

#include <iostream>
#include <string>

#include "System/String.h"
#include "OS.h"
#include "System/Exception.h"
#include "System/DateTime.h"

#include "pragmas.h"

namespace System
{
    class Environment
    {
    public:
        static System::String CurrentDirectory()
        {
            // TODO move this centrally
            char buffer[1024];

            // TODO this should be made platform independent
            if (getcwd(buffer, sizeof(buffer))) {
                return System::String(buffer);
            }
            return System::String("");
        }
    };
}

using namespace System;

#endif
