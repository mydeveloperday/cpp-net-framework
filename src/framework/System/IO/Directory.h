#ifndef _INCLUDED_SYSTEM_DIRECTORY_H_
#define _INCLUDED_SYSTEM_DIRECTORY_H_

#include "System/String.h"
#include "System/IO.h"
#include "System/IO/FileSystemInfo.h"

namespace System
{
    class Directory
    {
    public:
        /// determine if the file exists
        static void CreateDirectory(const System::String& file)
        {
            mkdir(file.str().c_str(),
                  S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
        }

        static void Delete(const System::String& file)
        {
            rmdir(file.str().c_str());
        }
    
    };

    class DirectoryInfo : public FileSystemInfo
    {
        public:
        DirectoryInfo()
        {}

        DirectoryInfo(const System::String & dir):
            FileSystemInfo(dir)
        {}
    };
}

using namespace System;

#endif
