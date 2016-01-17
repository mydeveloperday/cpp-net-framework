#ifndef _INCLUDED_SYSTEM_ENVIRONMENT_H_
#define _INCLUDED_SYSTEM_ENVIRONMENT_H_

#include "System/String.h"
#include "OS.h"

#include "pragmas.h"

namespace System
{
    /// a class for holding information about the OS environment
    class Environment
    {
    public:
        /// get the current working directory
        static System::String CurrentDirectory()
        {
            // TODO move this centrally
            char buffer[1024];

            // TODO this should be made platform independent and more secure
            char* nbuff = getcwd(buffer, sizeof(buffer));

            return System::String(nbuff ? buffer : "");
        }
    };
}

using namespace System;

#endif
