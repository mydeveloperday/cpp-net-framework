#ifndef _INCLUDED_SYSTEM_DIRECTORY_H_
#define _INCLUDED_SYSTEM_DIRECTORY_H_

#include "System/String.h"
#include "System/IO.h"
#include "System/IO/FileSystemInfo.h"
#include "System/IO/FileInfo.h"
#include "System/Array.h"
#include "System/Collections/Generic.h"

#include <dirent.h>

namespace System
{
    namespace IO
    {
    class FileInfo;    
        
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
        
        Array<System::IO::FileInfo> GetFiles();
    };
    
    }
}

using namespace System;
using namespace System::IO;

#endif
