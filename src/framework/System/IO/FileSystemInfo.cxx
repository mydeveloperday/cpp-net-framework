#include "FileInfo.h"

FileSystemInfo::FileSystemInfo(const System::String& s)
    : m_path(s)
{
    String cwd = Environment::CurrentDirectory();
    m_path = System::Path::Combine(cwd, s);
}
