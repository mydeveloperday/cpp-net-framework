<<<<<<< HEAD:src/framework/Exception.h
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

        String Message()
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
=======
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
>>>>>>> a30a7cc330fa54010280ba40246ca6e89193bffa:src/framework/System/Exception.h
