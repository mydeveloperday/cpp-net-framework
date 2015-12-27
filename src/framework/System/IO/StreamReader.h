#ifndef _INCLUDED_SYSTEM_IO_STREAMREADER_H_
#define _INCLUDED_SYSTEM_IO_STREAMREADER_H_

#include <fstream>
#include <memory>

#include "System.h"
#include "Path.h"
#include "System/IO/FileInfo.h"
#include "System/IO/FileNotFoundException.h"
#include "OS.h"

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
            StreamReader(const System::String& file);

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

                System::String sIn(strIn);
                System::String strOut = sIn.Replace("\r","");
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
