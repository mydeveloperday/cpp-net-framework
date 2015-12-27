#ifndef _INCLUDED_SYSTEM_PATH_H_
#define _INCLUDED_SYSTEM_PATH_H_

#include "System/String.h"
#include "System/IO.h"

namespace System
{
	/// a utility class for path based operations
    class Path
    {
    public:
		/// join 2 directory/files together with a path seperator / 
        static System::String Combine(const System::String &a, 
                                      const System::String &b);

        /// get the filename for from the path
        static System::String GetFileName(const System::String &a);

        static System::String GetFullPath(const System::String &a);
    };
}

using namespace System;

#endif
