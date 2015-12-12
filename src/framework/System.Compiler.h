#ifndef _INCLUDED_SYSTEM_COMPILER_H_
#define _INCLUDED_SYSTEM_COMPILER_H_

#include "System.h"
#include "OS.h"

namespace System
{
    namespace Compiler
    {
        class Internals
        {
        public:
            static String CompilerName()
            {
                return "gcc";
            }
        };
    }
}

using namespace System::IO;

#endif
