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
        System::String m_path;

      public:
        FileInfo()
        {}

        FileInfo(const System::String &s):
            m_path(s)
        {
            String cwd = Environment::CurrentDirectory();
            m_path = Path::Combine(cwd, s);
        }

        System::String FullName() const
        {
            return m_path;
        }

        bool Exists() const
        {
            struct stat statStruct;
            bool fileExists= (stat (m_path.str().c_str(), &statStruct) == 0);
            return fileExists;
        }

        String Extension() const
        {
            int dotPos = m_path.LastIndexOf('.');
            if (dotPos == -1) {
                return String("");
            }
            // Extension include the "."
            String ext=m_path.Substring(dotPos);
            return ext;
        }

        String Name() const
        {
            // from the end of the path back up to the last / or \\ to strip to the filename
            int lastForwardSlash = m_path.LastIndexOf('/');
            int lastBackwardSlash = m_path.LastIndexOf('\\');

            if (lastForwardSlash == -1 && lastBackwardSlash == -1) {
                return m_path;
            }

            if (lastForwardSlash == -1) {
                return m_path.Substring(lastBackwardSlash+1);
            }
            if (lastBackwardSlash == -1) {
                return m_path.Substring(lastForwardSlash+1);
            }
            return m_path;
        }

        DateTime CreationTime()
        {
        }
    };

    class StreamWriter
    {
        System::String  m_file;
        std::ofstream   m_fd;
        bool            m_disposed;

        public:
        StreamWriter(const System::String &file):
            m_file(file),
            m_disposed(false)
        {
           m_fd = std::ofstream(file.str());
        }

        ~StreamWriter()
        {
            Dispose();
        }

        void WriteLine(const System::String &s)
        {
            m_fd << s.str() << "\n";
        }

        void Dispose()
        {
            if (!m_disposed) {
                m_fd.close();
                m_disposed = true;
            }
        }
    };

     class FileNotFoundException : public System::Exception
     {
        public:
            FileNotFoundException()
            {}
     };

    class StreamReader
    {
        System::String  m_file;
        std::ifstream   m_fd;
        bool            m_disposed;

    public:
        StreamReader(const System::String &file) :
            m_file(file),
            m_disposed(false)
        {
            FileInfo info(file);
            if (!info.Exists()) {
                throw System::IO::FileNotFoundException();
            }

            std::string path = info.FullName().str();

            m_fd = std::ifstream(path);
        }

        ~StreamReader()
        {
            m_fd.close();
        }

        System::String ReadLine()
        {
            std::string strIn;
            std::getline(m_fd, strIn);

            System::String strOut(strIn.c_str());
            return strOut;
        }

        void Dispose()
        {
            if (!m_disposed) {
                m_fd.close();
                m_disposed = true;
            }
        }

        bool EndOfStream()
        {
            return !m_fd || m_fd.eof();
        }
    };
  }
}

using namespace System::IO;

#endif
