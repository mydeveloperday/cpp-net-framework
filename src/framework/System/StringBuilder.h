#ifndef _INCLUDED_SYSTEM_STRINGBUILDER_H_
#define _INCLUDED_SYSTEM_STRINGBUILDER_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

#include "pragmas.h"

#include "System/Object.h"

namespace System
{
	/// A string builder class
    class StringBuilder : public Object
    {
        String m_str;

    public:
        /// constructor
        StringBuilder()
        {
        }

		/// add a .net string
		void Append(const String &s)
		{
			m_str+=s;
		}

		/// add a string literal
		void Append(const char *s)
		{
			m_str+=s;
		}
        
        /// add a character literal
        void Append(char c)
		{
			m_str+=c;
		}
	
		/// to .NET string override
		virtual String ToString()
		{
			return m_str.ToString();
		}
        
        /// empty the string
        void Clear()
        {
            m_str.Clear();
        }
    };
}

using namespace System;

#endif
