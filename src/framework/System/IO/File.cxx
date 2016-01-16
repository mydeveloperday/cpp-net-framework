
#include "File.h"
#include "System/IO.h"

bool File::Exists(const String& file)
{
    FileInfo info(file);
    return info.Exists();
}
