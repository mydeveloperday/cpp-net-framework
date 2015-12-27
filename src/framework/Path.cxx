#include "System/IO.h"

System::String Path::Combine(const System::String &a, 
                              const System::String &b)
{
    String res = a + PATH_SEPARATOR + b;
    return res;
}

System::String Path::GetFileName(const System::String &a)
{
    FileInfo info(a);
    return info.Name();
}

System::String Path::GetFullPath(const System::String &a)
{
    FileInfo info(a);
    return info.FullName();
}

