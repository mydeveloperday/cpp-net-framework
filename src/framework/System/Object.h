#ifndef _INCLUDED_SYSTEM_OBJECT_H_
#define _INCLUDED_SYSTEM_OBJECT_H_

#include "OS.h"

#include "pragmas.h"

namespace System
{
    class String;

    /// Object class
    class Object
    {
    public:
        /// Constructor
        Object()
        {
        }

        virtual ~Object()
        {
        }

        virtual String ToString();
    };
}

using namespace System;

#endif
