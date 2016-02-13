#ifndef _INCLUDED_SYSTEM_DIRECTORY_H_
#define _INCLUDED_SYSTEM_DIRECTORY_H_

#include "System/String.h"
#include "System/IO.h"

namespace System
{
    class Directory
    {
    public:
        /// determine if the file exists
        static void CreateDirectory(const System::String& file)
        {
            static_cast<void>(file);
        }

        static void Delete(const System::String& file)
        {
            static_cast<void>(file);
        }
    
    };
}

using namespace System;

#endif
