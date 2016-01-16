#ifndef _INCLUDED_SYSTEM_IO_FILENOTFOUNDEXCEPTION_H_
#define _INCLUDED_SYSTEM_IO_FILENOTFOUNDEXCEPTION_H_

#include <fstream>
#include <memory>

#include "System.h"
#include "System/Exception.h"

#include "OS.h"

namespace System
{
    namespace IO
    {
        /// A exception throw when a file cannot be found
        class FileNotFoundException : public System::Exception
        {
        public:
            /// constructor
            FileNotFoundException()
                : System::Exception("File not Found:")
            {
            }

            /// constrcutor with reason
            FileNotFoundException(const String& msg)
                : System::Exception(msg)
            {
            }
        };
    }
}

using namespace System::IO;

#endif
