#ifndef _INCLUDED_SYSTEM_IO_H_
#define _INCLUDED_SYSTEM_IO_H_

#include "System.h"

#include "OS.h"

#include <fstream>

namespace System
{
  namespace IO
  {
    class FileInfo
    {
        System::string m_path;

      public:
        FileInfo()
        {}

        FileInfo(const System::string &s):
            m_path(s)
        {
        }

        bool Exists()
        {
            struct stat buffer;   
            return (stat (m_path.str().c_str(), &buffer) == 0);
        }
    };

    class StreamWriter
    {
        System::string m_file;
        std::ofstream   m_fd;

        public:
        StreamWriter(const System::string &file):
            m_file(file)
        {
           m_fd = std::ofstream(file.str()); 
        }

        ~StreamWriter()
        {
           m_fd.close();
        }

        void WriteLine(const System::string &s)
        {
            m_fd << s.str() << "\n";
        }
    };
  }
}

using namespace System::IO;

#endif
