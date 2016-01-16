
#include "System.h"

namespace System
{
    void PrintTo(const System::String& str, ::std::ostream* os)
    {
        *os << str.str().c_str();
    }
}
