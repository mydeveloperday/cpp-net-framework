
#include "sys/stat.h"

#ifdef _WIN32
#include <direct.h>
#define PATH_SEPARATOR "\\"
#else
#include "unistd.h"
#include "NullPtr.h"
#define PATH_SEPARATOR "/"
#endif
