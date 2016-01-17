#include "StreamReader.h"

#include "System/String.h"

namespace System
{
    namespace IO
    {
        /// constructor
        StreamReader::StreamReader(const System::String& file)
            : m_file(file)
            , m_disposed(false)
        {
            FileInfo info(file);
            if (string::IsNullOrEmpty(info.Name())) {
                throw System::IO::FileNotFoundException();
            }
            if (!info.Exists()) {
                throw System::IO::FileNotFoundException(
                    "File Not Found:" + info.Name());
            }

            std::string path = info.FullName().str();

#if defined(SUPPORTS_CPLUSPLUS_11)
// m_fd = std::shared_ptr<std::ifstream>(new std::ifstream(path.c_str()));
#else
            m_fd = new std::ifstream(path.c_str());
#endif
        }
    }
}
