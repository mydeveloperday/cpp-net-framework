
#include "sys/stat.h"

#ifdef _WIN32

#include <direct.h>
#define PATH_SEPARATOR "\\"
#define SUPPORTS_NULLPTR

#elif defined(_APPLE_)

#include "unistd.h"
#define SUPPORTS_NULLPTR
#define PATH_SEPARATOR "/"

#else

#include "unistd.h"
#include "NullPtr.h"
#define PATH_SEPARATOR "/"

#endif

