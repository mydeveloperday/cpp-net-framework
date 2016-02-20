
#include "Directory.h"

#include <dirent.h>

Array<System::IO::FileInfo> System::IO::DirectoryInfo::GetFiles()
{
    List<System::IO::FileInfo> files;
    
    String currentPath = FullName();
    
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (currentPath.str().c_str())) != nullptr) {
            while ((ent = readdir (dir)) != nullptr) {
            // we need to be careful here because of the way
            // we have FileInfo contrsutor working                   
            System::IO::FileInfo file(ent->d_name);
            files.Add(file);
            }
            closedir (dir);
    }              
    return files.ToArray();
}
