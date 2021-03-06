#ifndef _INCLUDED_SYSTEM_DIRECTORY_H_
#define _INCLUDED_SYSTEM_DIRECTORY_H_

#include "System/String.h"
#include "System/IO.h"
#include "System/IO/FileSystemInfo.h"
#include "System/IO/FileInfo.h"
#include "System/Array.h"
#include "System/Collections/Generic.h"


namespace System
{
    namespace IO
    {
    class FileInfo;    
        
    /// the directory class
    class Directory
    {
    public:
        /// determine if the file exists
        static void CreateDirectory(const System::String& file);

        /// delete a named directory
        static void Delete(const System::String& file);

    };

    /// directory info class
    class DirectoryInfo : public FileSystemInfo
    {
        public:
        /// default constructor
        DirectoryInfo()
        {}

        /// constructor
        DirectoryInfo(const System::String & dir):
            FileSystemInfo(dir)
        {}
        
        // get the files in the directory
        Array<System::IO::FileInfo> GetFiles();
    };
    
    }
}

using namespace System;
using namespace System::IO;

#endif
