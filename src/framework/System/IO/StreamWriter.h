#ifndef _INCLUDED_SYSTEM_IO_STREAMWRITER_H_
#define _INCLUDED_SYSTEM_IO_STREAMWRITER_H_

#include <fstream>
#include <memory>

#include "System.h"
#include "Path.h"

#include "OS.h"

namespace System
{
    namespace IO
    {
		/// a class for writing out to a file
        class StreamWriter
        {
            System::String m_file;
#if defined (SUPPORTS_CPLUSPLUS_11)
            std::shared_ptr<std::ofstream> m_fd;
#else
            std::ofstream* m_fd;
#endif
            bool m_disposed;

        public:
            /// constructor
            StreamWriter(const System::String& file)
                : m_file(file)
                , m_disposed(false)
            {
#if defined (SUPPORTS_CPLUSPLUS_11)
                m_fd = std::shared_ptr<std::ofstream>(new std::ofstream(file.str().c_str(),std::ios::binary));
#else
                m_fd = new std::ofstream(file.str().c_str(),std::ios::binary);
#endif
            }

            /// destructor
            virtual ~StreamWriter()
            {
                Dispose();
            }

            /// write a line to the file
            void WriteLine(const System::String& s)
            {
                (*m_fd) << s.str() << "\n";
            }

            /// call the dispose method
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
        };
    }
}

using namespace System::IO;

#endif
