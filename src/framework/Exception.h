#ifndef _INCLUDED_SYSTEM_H_
#define _INCLUDED_SYSTEM_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "NetString.h"
#include "OS.h"

#pragma warning(disable: 4100)
#pragma warning(disable: 4505)

// localtime TODO replace with secure call
#pragma warning(push)
#pragma warning(disable: 4996)

namespace System
{
    class Exception : std::exception
    {
        String m_msg;
    public:
        Exception()
        {}

        virtual const char* what() const OVERRIDE
        {
            return m_msg.str();
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

#pragma warning(pop)

#endif
