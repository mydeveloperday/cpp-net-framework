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

        /// the length of the buffer
        int Length()
        {
            return m_str.Length();
        }

        // the maximum capacity
        int MaxCapacity()
        {
            // TODO there is no capacity at present
            return (Length()*2);
        }

        /// the capacity of the string
        int Capacity(){
            return MaxCapacity();
        }

        /// the index operator
        char operator[](int index) const
        {
            return m_str[index];
        }
    };
}

using namespace System;

#endif
