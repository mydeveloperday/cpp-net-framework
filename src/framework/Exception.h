#ifndef _INCLUDED_SYSTEM_EXCEPTION_H_
#define _INCLUDED_SYSTEM_EXCEPTION_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "NetString.h"
#include "OS.h"

#include "pragmas.h"

namespace System
{
    class Exception : std::exception
    {
        String m_msg;

    public:
        Exception()
        {}

        virtual const char* what() const
        {
            return m_msg.str().c_str();
        }

        Exception(String msg) :
            m_msg(msg)
        {}

        String Message()
        {
            return what();
        }
    };

    class SystemException : Exception
    {
    public:
        SystemException()
        {}

        SystemException(String msg) :
            Exception(msg)
        {}
    };

    class NotImplementedException : SystemException
    {
    public:
        NotImplementedException()
        {}

        NotImplementedException(String msg):
            SystemException(msg)
        {}
    };

}

using namespace System;

#endif
