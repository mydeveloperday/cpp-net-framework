#ifndef _INCLUDED_SYSTEM_IO_FILENOTFOUNDEXCEPTION_H_
#define _INCLUDED_SYSTEM_IO_FILENOTFOUNDEXCEPTION_H_

#include <fstream>
#include <memory>

#include "System.h"
#include "Path.h"

#include "OS.h"

namespace System
{
    namespace IO
    {
        class FileNotFoundException : public System::Exception
        {
        public:
            FileNotFoundException()
            {
            }
        };
    }
}

using namespace System::IO;

#endif
