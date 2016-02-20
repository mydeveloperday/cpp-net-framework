
#include "sys/stat.h"

#ifdef _WIN32

#include <windows.h>
#include <direct.h>
#define PATH_SEPARATOR "\\"
#define SUPPORTS_NULLPTR

#elif defined(_APPLE_)

#include "unistd.h"
#include <dirent.h>
#define SUPPORTS_NULLPTR
#define PATH_SEPARATOR "/"
#define SUPPORT_DIRENT

#else

#include "unistd.h"
#include <dirent.h>
#include "NullPtr.h"
#define PATH_SEPARATOR "/"
#define SUPPORT_DIRENT

#endif

// for when C++11 is supported
#ifdef SUPPORTS_CXX_11
#define OVERRIDE override
#else
#define OVERRIDE 
#endif

#include <stdint.h>
