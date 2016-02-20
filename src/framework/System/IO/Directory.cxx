
#include "Directory.h"


Array<System::IO::FileInfo> System::IO::DirectoryInfo::GetFiles()
{
    List<System::IO::FileInfo> files;
    
    String currentPath = FullName();

#ifdef SUPPORT_DIRENT  
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (currentPath.c_str())) != nullptr) {
            while ((ent = readdir (dir)) != nullptr) {
            // we need to be careful here because of the way
            // we have FileInfo contrsutor working                   
            System::IO::FileInfo file(ent->d_name);
            files.Add(file);
            }
            closedir (dir);
    }  
#else 
   WIN32_FIND_DATA ffd;
   TCHAR szDir[MAX_PATH];
   HANDLE hFind = INVALID_HANDLE_VALUE;
   hFind = FindFirstFile(currentPath.c_str(), &ffd);
   
   do
   {
      if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
      {
         // is a directory ffd.cFileName;
      }
      else
      {
         // ffd.cFileName
         System::IO::FileInfo file(String(ffd.cFileName));
         files.Add(file);
      }
   }
   while (FindNextFile(hFind, &ffd) != 0);
   
#endif           
    return files.ToArray();
}
