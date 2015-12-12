<<<<<<< HEAD:src/framework/Environment.h
#ifndef _INCLUDED_SYSTEM_ENVIRONMENT_H_
#define _INCLUDED_SYSTEM_ENVIRONMENT_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "NetString.h"
#include "OS.h"
#include "Exception.h"
#include "DateTime.h"

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
=======
#ifndef _INCLUDED_SYSTEM_ENVIRONMENT_H_
#define _INCLUDED_SYSTEM_ENVIRONMENT_H_

#include "System/String.h"
#include "OS.h"

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

            // TODO this should be made platform independent and more secure
            char* nbuff = getcwd(buffer, sizeof(buffer));

            return System::String( nbuff ? buffer : "");
        }
    };
}

using namespace System;

#endif
>>>>>>> a30a7cc330fa54010280ba40246ca6e89193bffa:src/framework/System/Environment.h
