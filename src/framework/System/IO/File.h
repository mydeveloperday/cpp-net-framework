#ifndef _INCLUDED_SYSTEM_FILE_H_
#define _INCLUDED_SYSTEM_FILE_H_

#include "System/String.h"
#include "System/IO.h"

namespace System
{
    /// a utility class for path based operations
    class File
    {
    public:
        /// determine if the file exists
        static bool Exists(const System::String& file);
    };
}

using namespace System;

#endif
