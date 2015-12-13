#ifndef _INCLUDED_SYSTEM_EXCEPTION_H_
#define _INCLUDED_SYSTEM_EXCEPTION_H_

#include "System/String.h"
#include "OS.h"

#include "pragmas.h"

namespace System
{
    class Exception : public std::exception
    {
        std::string m_reason;

    public:
        Exception()
        {
        }

        virtual ~Exception() throw()
        {
        }

        Exception(const String& msg)
        {
            m_reason = msg.str();
        }

        virtual const char* what() const throw() {
            return m_reason.c_str();
        }

        String Message() const
        {
            return m_reason;
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
