#ifndef _INCLUDED_SYSTEM_EXCEPTION_H_
#define _INCLUDED_SYSTEM_EXCEPTION_H_

#include "System/String.h"
#include "OS.h"

#include "pragmas.h"

namespace System
{
    class Exception : public std::exception
    {
        String m_msg;

    public:
        Exception()
        {
        }

        virtual ~Exception() throw()
        {
        }

        /*
        virtual const char* what() const throw()
        {
            return m_msg.str().c_str();
        }
        */

        Exception(String msg)
            : m_msg(msg)
        {
        }

        String Message() const
        {
            return what();
        }
    };

    class SystemException : public Exception
    {
    public:
        SystemException()
        {
        }

        SystemException(String msg)
            : Exception(msg)
        {
        }
    };

    class NotImplementedException : public SystemException
    {
    public:
        NotImplementedException()
        {
        }

        NotImplementedException(String msg)
            : SystemException(msg)
        {
        }
    };
}

using namespace System;

#endif
