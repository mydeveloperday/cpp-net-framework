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
#ifdef _MSVC
                return "msvc";
#elif defined(__clang__)
                return "clang";
#else
                return "gcc";
#endif
            }
        };
    }
}

using namespace System::Compiler;

#endif
