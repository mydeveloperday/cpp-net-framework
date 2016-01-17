#ifndef _INCLUDED_SYSTEM_EXCEPTION_H_
#define _INCLUDED_SYSTEM_EXCEPTION_H_

#include "System/String.h"
#include "OS.h"

#include "pragmas.h"

namespace System
{
    /// Base exception class System::Exception
    class Exception : public std::exception
    {
        std::string m_reason;

    public:
        /// exception constructor
        Exception()
        {
        }

        /// exception destructor
        virtual ~Exception() throw()
        {
        }

        /// exception construction with reason string
        Exception(const String& msg)
        {
            m_reason = msg.str();
        }

        /// what is the cause of the exception with std::exception api
        virtual const char* what() const throw()
        {
            return m_reason.c_str();
        }

        /// get the reason with .NET API
        String Message() const
        {
            return m_reason;
        }
    };

    /// A system exception for OS related failures
    class SystemException : public Exception
    {
    public:
        /// system exception constructor
        SystemException()
        {
        }

        /// system exception constructor with reason
        SystemException(String msg)
            : Exception(msg)
        {
        }
    };

    /// Not implemented exception
    class NotImplementedException : public SystemException
    {
    public:
        /// not implemented exception constructor
        NotImplementedException()
        {
        }

        /// not implemented exception constructor with reason
        NotImplementedException(String msg)
            : SystemException(msg)
        {
        }
    };
}

using namespace System;

#endif
