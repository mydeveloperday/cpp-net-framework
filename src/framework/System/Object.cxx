
#include "System/Object.h"
#include "System/String.h"

namespace System
{
    /// basic to string operation of all base classes
    String Object::ToString()
    {
        return String("Object");
    }
}
