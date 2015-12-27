#ifndef _INCLUDED_SYSTEM_STRING_H_
#define _INCLUDED_SYSTEM_STRING_H_

#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

#include "pragmas.h"

#include "System/Object.h"

typedef char Char;

namespace System
{
	enum StringComparison { OrdinalIgnoreCase }; 

	/// A generalized string class
    class String : public Object
    {
        std::string m_str;

    public:
        /// constructor
        String()
        {
        }

        /// constructors from literal string
        String(const char* strIn)
            : m_str(strIn)
        {
        }

        /// constructor from std::string (NOT .NET API)
        String(const std::string& strIn)
            : m_str(strIn)
        {
        }

        /// get the std::string from the String (NOT .NET call)
        std::string str() const
        {
            return m_str;
        }

        // an std::string casting converter (NOT .NET call)
        const std::string operator()(std::string&) const
        {
            return str();
        }

        // an const char* casting converter (NOT .NET call)
        const char* operator()(const char*) const
        {
            return str().c_str();
        }

        /// a function to determine if the string is empty (NOT .NET call)
        bool Empty() const
        {
            return (Length() == 0);
        }

		/// the size of the string
        int Length() const
        {
            return m_str.size();
        }

		/// the indexing function
        Char operator[](int pos) const
        {
            return m_str[pos];
        }

		/// string character += operator
        String& operator+=(Char c)
        {
            std::string newstring = (*this).str() + c;
            m_str = newstring;
            return (*this);
        }

		/// string += operator
        String& operator+=(const String& s)
        {
            std::string newstring = (*this).str() + s.str();
            m_str = newstring;
            return (*this);
        }

		/// make an upper case version of the string
        String ToUpper() const
        {
            String s;
            for (size_t i = 0; i < m_str.size(); ++i) {
                s += static_cast<char>(toupper(m_str[i]));
            }
            return s;
        }

		/// make a lower case version of the string
        String ToLower() const
        {
            String s;
            for (size_t i = 0; i < m_str.size(); ++i) {
                s += static_cast<char>(tolower(m_str[i]));
            }
            return s;
        }

		/// does the string contain the specified string
        bool Contains(String s) const
        {
            if (str().find(s.str()) != std::string::npos) {
                return true;
            }
            return false;
        }

		/// an equals operator
        bool Equals(String s) const
        {
            return (str() == s.str());
        }


        bool Equals(String s,StringComparison) const
        {
            return (str() == s.str());
        }

        String Substring(int start) const
        {
            std::string newstring = str().substr(start);
            return String(newstring.c_str());
        }

        String Substring(int start, int length) const
        {
            std::string newstring = str().substr(start, length);
            return String(newstring.c_str());
        }

        int LastIndexOf(char c) const
        {
            size_t pos = str().rfind(c);
            if (pos == std::string::npos) {
                return -1;
            }
            return static_cast<int>(pos);
        }

        int LastIndexOf(const String& s) const
        {
            size_t pos = str().rfind(s.str());
            if (pos == std::string::npos) {
                return -1;
            }
            return static_cast<int>(pos);
        }

        int IndexOf(char c) const
        {
            size_t pos = str().find(c);
            if (pos == std::string::npos) {
                return -1;
            }
            return static_cast<int>(pos);
        }

        int IndexOf(const String& s) const
        {
            size_t pos = str().find(s.str());
            if (pos == std::string::npos) {
                return -1;
            }
            return static_cast<int>(pos);
        }

        bool StartsWith(const String& s) const
        {
            if (String::IsNullOrEmpty(s)) {
                return false;
            }
            return (IndexOf(s) == 0);
        }

        bool EndsWith(const String& s) const
        {
            if (String::IsNullOrEmpty(s)) {
                return false;
            }
            return (IndexOf(s) == Length() - s.Length());
        }

        String Replace(const String& from, const String& with)
        {
            int pos = IndexOf(from);
            if (pos == -1) {
                return (*this);
            }

            String newstring = (*this);

            newstring.m_str.replace(pos, pos + from.Length(), with.str());

            return newstring;
        }

        String Trim() const
        {
            String s = (*this);
			if (String::IsNullOrEmpty(s)){
				return s;
			}
            s = s.TrimEnd();
            s = s.TrimStart();
            return s;
        }

        String TrimEnd() const
        {
            String s = (*this);
			if (String::IsNullOrEmpty(s)){
				return s;
			}
            s.m_str.erase(s.m_str.find_last_not_of(" \n\r\t") + 1);
            return s;
        }

        String TrimStart() const
        {
            String s = (*this);
			if (String::IsNullOrEmpty(s)){
				return s;
			}
            s = s.Substring(s.m_str.find_first_not_of(" \n\r\t"));
            return s;
        }

        static bool IsNullOrEmpty(const String &s)
        {
            return (s.Length() == 0);
        }

		virtual String ToString()
		{
			return (*this);
		}
    };

    inline String operator+(const String& a, const String& b)
    {
        std::string m_res = a.str();
        m_res += b.str();
        return String(m_res.c_str());
    }

    inline String Concat(const String& a, const String& b)
    {
        std::string m_res = a.str();
        m_res += b.str();
        return String(m_res.c_str());
    }

    inline bool operator==(const String& a, const String& b)
    {
        return (a.str() == b.str());
    }

    inline bool operator!=(const String& a, const String& b)
    {
        return (a.str() != b.str());
    }
    
    inline bool operator< (const String& a, const String& b)
    {
        return (a.str() < b.str());
    }

    void PrintTo(const System::String& str, ::std::ostream* os);
}

typedef System::String string;

using namespace System;

#endif
