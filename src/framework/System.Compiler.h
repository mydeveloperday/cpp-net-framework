#ifndef _INCLUDED_SYSTEM_COMPILER_H_
#define _INCLUDED_SYSTEM_COMPILER_H_

#include "System.h"
#include "OS.h"

// when C++ 11 override this with 'override'
#define OVERRIDE 

namespace System
{
    namespace Compiler
    {
		/// a class for helping the build system determine the compiler type
        class Internals
        {
        public:
            /// get the name of the compiler
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
