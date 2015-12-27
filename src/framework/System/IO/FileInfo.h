#ifndef _INCLUDED_SYSTEM_IO_FILEINFO_H_
#define _INCLUDED_SYSTEM_IO_FILEINFO_H_

#include <fstream>
#include <memory>

#include "System.h"
#include "Path.h"
#include "System/DateTime.h"
#include "OS.h"

namespace System
{
    namespace IO
    {
		/// A file information class
        class FileInfo
        {
            System::String m_path;

        public:
            /// constructor
            FileInfo()
            {
            }

            /// constructor within the current directory
            FileInfo(const System::String& s);

            /// the full name of the file
            System::String FullName() const
            {
                return m_path;
            }

            /// does the file exist
            bool Exists() const
            {
                struct stat statStruct;
                bool fileExists =
                    (stat(m_path.str().c_str(), &statStruct) == 0);
                return fileExists;
            }

            /// the files extension
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

            /// the name of the file
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
                    String part = m_path.Substring(lastBackwardSlash + 1);
                    return part;
                }
                if (lastBackwardSlash == -1) {
                    String part = m_path.Substring(lastForwardSlash + 1);
                    return part;
                }

                String part = m_path.Substring(Math::Max(lastForwardSlash,lastBackwardSlash) + 1);
                return part;
            }

            /// delete the file
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

            /// get the creation date of the file
            DateTime CreationTime()
            {
                throw System::NotImplementedException("FileInfo::Creation time not implemented");
            }
        };
    }
}

using namespace System::IO;

#endif
