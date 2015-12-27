#ifndef _INCLUDED_SYSTEM_IO_STREAMREADER_H_
#define _INCLUDED_SYSTEM_IO_STREAMREADER_H_

#include <fstream>
#include <memory>

#include "System.h"
#include "Path.h"

#include "OS.h"

#include "System/IO/FileNotFoundException.h"

namespace System
{
    namespace IO
    {
		/// a class for reading a file
        class StreamReader
        {
            System::String m_file;
            // TODO C++ 11 (Travis-CI is prevent me from turning this on)
#if defined (SUPPORTS_CPLUSPLUS_11)
            std::shared_ptr<std::ifstream> m_fd;
#else
            std::ifstream *m_fd;
#endif
            bool m_disposed;

        public:
            /// constructor
            StreamReader(const System::String& file)
                : m_file(file)
                , m_disposed(false)
            {
                FileInfo info(file);
                if (string::IsNullOrEmpty(info.Name())) {
                    throw System::IO::FileNotFoundException();
                }
                if (!info.Exists()) {
                    throw System::IO::FileNotFoundException("File Not Found:"+info.Name());
                }

                std::string path = info.FullName().str();

#if defined (SUPPORTS_CPLUSPLUS_11)
                //m_fd = std::shared_ptr<std::ifstream>(new std::ifstream(path.c_str()));
#else
                m_fd = new std::ifstream(path.c_str());
#endif
            }

            /// destructor
            ~StreamReader()
            {
                Dispose();
            }

            /// read a line from the file
            System::String ReadLine()
            {
                std::string strIn;
                std::getline((*m_fd), strIn);

                System::String strOut(strIn.c_str());
                return strOut;
            }

            /// dispose method for closing the file
            void Dispose()
            {
                if (!m_disposed) {
                    (*m_fd).close();
#if !defined (SUPPORTS_CPLUSPLUS_11)
                    delete m_fd;
#endif
                    m_disposed = true;
                }
            }

            /// is the stream at the end
            bool EndOfStream()
            {
                return !(*m_fd) || (*m_fd).eof();
            }
        };
    }
}

using namespace System::IO;

#endif
