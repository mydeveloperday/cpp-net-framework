
#include "sys/stat.h"

#ifdef _WIN32
#include <direct.h>
#else
#include "unistd.h"
#include "NullPtr.h"
#endif
