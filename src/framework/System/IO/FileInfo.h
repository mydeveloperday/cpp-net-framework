#ifndef _INCLUDED_SYSTEM_IO_FILEINFO_H_
#define _INCLUDED_SYSTEM_IO_FILEINFO_H_

#include <fstream>
#include <memory>

#include "System.h"
#include "Path.h"
#include "System/DateTime.h"
#include "OS.h"
#include "System/IO/FileSystemInfo.h"

namespace System
{
    namespace IO
    {
        /// A file information class
        class FileInfo : public FileSystemInfo
        {
        public:
            /// constructor
            FileInfo()
            {
            }

            /// constructor within the current directory
            FileInfo(const System::String& s);
        };
    }
}

using namespace System::IO;

#endif
