#include "FileInfo.h"

FileInfo::FileInfo(const System::String& s)
         : m_path(s)
{
    String cwd = Environment::CurrentDirectory();
    m_path = System::Path::Combine(cwd, s);
}
