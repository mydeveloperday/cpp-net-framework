#ifndef _INCLUDED_SYSTEM_IO_H_
#define _INCLUDED_SYSTEM_IO_H_

#include <fstream>
#include <memory>

#include "System.h"
#include "Path.h"

#include "OS.h"

namespace System
{
    namespace IO
    {
        class FileInfo
        {
            System::String m_path;

        public:
            FileInfo()
            {
            }

            FileInfo(const System::String& s)
                : m_path(s)
            {
                String cwd = Environment::CurrentDirectory();
                m_path = System::Path::Combine(cwd, s);
            }

            System::String FullName() const
            {
                return m_path;
            }

            bool Exists() const
            {
                struct stat statStruct;
                bool fileExists =
                    (stat(m_path.str().c_str(), &statStruct) == 0);
                return fileExists;
            }

            String Extension() const
            {
                int dotPos = m_path.LastIndexOf('.');
                if (dotPos == -1) {
                    return String("");
                }
                // Extension include the "."
                String ext = m_path.Substring(dotPos);
                return ext;
            }

            String Name() const
            {
                // from the end of the path back up to the last / or \\ to strip
                // to the filename
                int lastForwardSlash = m_path.LastIndexOf('/');
                int lastBackwardSlash = m_path.LastIndexOf('\\');

                if (lastForwardSlash == -1 && lastBackwardSlash == -1) {
                    return m_path;
                }

                if (lastForwardSlash == -1) {
                    return m_path.Substring(lastBackwardSlash + 1);
                }
                if (lastBackwardSlash == -1) {
                    return m_path.Substring(lastForwardSlash + 1);
                }
                return m_path;
            }

            virtual void Delete()
            {
                int errVal = std::remove(FullName().str().c_str());
                if (errVal) {
                    // an error occurred TODO perhaps it should throw if not found)
                    // throw if a directory
                    static_cast<void>(errVal);
                }
                return;
            }

            DateTime CreationTime()
            {
                throw System::NotImplementedException("FileInfo::Creation time not implemented");
            }
        };

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
            StreamWriter(const System::String& file)
                : m_file(file)
                , m_disposed(false)
            {
#if defined (SUPPORTS_CPLUSPLUS_11)
                m_fd = std::shared_ptr<std::ofstream>(new std::ofstream(file.str().c_str()));
#else
                m_fd = new std::ofstream(file.str().c_str());
#endif
            }

            ~StreamWriter()
            {
                Dispose();
            }

            void WriteLine(const System::String& s)
            {
                (*m_fd) << s.str() << "\n";
            }

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

        class FileNotFoundException : public System::Exception
        {
        public:
            FileNotFoundException()
            {
            }
        };

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
            StreamReader(const System::String& file)
                : m_file(file)
                , m_disposed(false)
            {
                FileInfo info(file);
                if (!info.Exists()) {
                    throw System::IO::FileNotFoundException();
                }

                std::string path = info.FullName().str();

#if defined (SUPPORTS_CPLUSPLUS_11)
                //m_fd = std::shared_ptr<std::ifstream>(new std::ifstream(path.c_str()));
#else
                m_fd = new std::ifstream(path.c_str());
#endif
            }

            ~StreamReader()
            {
                Dispose();
            }

            System::String ReadLine()
            {
                std::string strIn;
                std::getline((*m_fd), strIn);

                System::String strOut(strIn.c_str());
                return strOut;
            }

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

            bool EndOfStream()
            {
                return !(*m_fd) || (*m_fd).eof();
            }
        };
    }
}

using namespace System::IO;

#endif
