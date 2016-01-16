#ifndef _INCLUDED_SYSTEM_STRING_H_
#define _INCLUDED_SYSTEM_STRING_H_

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctype.h>

#include "pragmas.h"

#include "System/Object.h"

namespace System
{
    /// string comparison enumeration
    typedef enum { Ordinal, OrdinalIgnoreCase } StringComparison;

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

        /// an std::string casting converter (NOT .NET call)
        const std::string operator()(std::string&) const
        {
            return str();
        }

        /// an const char* casting converter (NOT .NET call)
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
        char operator[](int pos) const
        {
            return m_str[pos];
        }

        /// string character += operator
        String& operator+=(char c)
        {
            std::string newstring = (*this).str() + c;
            m_str = newstring;
            return (*this);
        }

        /// string integer += operator
        String& operator+=(int i)
        {
            std::string newstring = (*this).str();

            std::string s;
            std::stringstream out;
            out << i;
            s = out.str();
            newstring += s;
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

        /// an equals operator using string comparison options
        bool Equals(String s, StringComparison comparison) const
        {
            if (comparison == OrdinalIgnoreCase) {
                String ns = s.ToLower();
                String ts = (*this).ToLower();
                return (ts.str() == ns.str());
            }
            return (str() == s.str());
        }

        /// return a substring of this string start at a given index
        String Substring(int start) const
        {
            std::string newstring = str().substr(start);
            return String(newstring.c_str());
        }

        /// return a substring of this string starting at the given index and of
        /// size length
        String Substring(int start, int length) const
        {
            std::string newstring = str().substr(start, length);
            return String(newstring.c_str());
        }

        /// the last index of this character
        int LastIndexOf(char c) const
        {
            size_t pos = str().rfind(c);
            if (pos == std::string::npos) {
                return -1;
            }
            return static_cast<int>(pos);
        }

        /// find the last index of the string
        int LastIndexOf(const String& s) const
        {
            size_t pos = str().rfind(s.str());
            if (pos == std::string::npos) {
                return -1;
            }
            return static_cast<int>(pos);
        }

        /// find the index of the character
        int IndexOf(char c) const
        {
            size_t pos = str().find(c);
            if (pos == std::string::npos) {
                return -1;
            }
            return static_cast<int>(pos);
        }

        /// find the index of the substring
        int IndexOf(const String& s) const
        {
            size_t pos = str().find(s.str());
            if (pos == std::string::npos) {
                return -1;
            }
            return static_cast<int>(pos);
        }

        /// does the string start with the specified string
        bool StartsWith(const String& s) const
        {
            if (String::IsNullOrEmpty(s)) {
                return false;
            }
            return (IndexOf(s) == 0);
        }

        /// does the string end with the specified string
        bool EndsWith(const String& s) const
        {
            if (String::IsNullOrEmpty(s)) {
                return false;
            }
            return (IndexOf(s) == Length() - s.Length());
        }

        /// replace one string with another
        String Replace(const String& from, const String& with)
        {
            if (from.Empty()) {
                return (*this);
            }

            std::string to = with.str();
            std::string str = (*this).str();

            size_t start_pos = 0;
            while ((start_pos = str.find(from.str(), start_pos)) !=
                std::string::npos) {
                str.replace(start_pos, from.str().length(), to);
                start_pos += to.length();
            }
            String newstring = str;
            return newstring;
        }

        /// remove leading and trailing spaces
        String Trim() const
        {
            String s = (*this);
            if (String::IsNullOrEmpty(s)) {
                return s;
            }
            s = s.TrimEnd();
            s = s.TrimStart();
            return s;
        }

        /// remove trailing spaces
        String TrimEnd() const
        {
            String s = (*this);
            if (String::IsNullOrEmpty(s)) {
                return s;
            }
            s.m_str.erase(s.m_str.find_last_not_of(" \n\r\t") + 1);
            return s;
        }

        /// remove leading spaces
        String TrimStart() const
        {
            String s = (*this);
            if (String::IsNullOrEmpty(s)) {
                return s;
            }
            s = s.Substring(s.m_str.find_first_not_of(" \n\r\t"));
            return s;
        }

        /// is the string null or empty
        static bool IsNullOrEmpty(const String& s)
        {
            return (s.Length() == 0);
        }

        /// turn the string into a string
        virtual String ToString()
        {
            return (*this);
        }

        /// empty the string
        void Clear()
        {
            m_str.clear();
        }
    };

    /// the plus operator for two strings
    inline String operator+(const String& a, const String& b)
    {
        std::string m_res = a.str();
        m_res += b.str();
        return String(m_res.c_str());
    }

    /// concat two strings together
    inline String Concat(const String& a, const String& b)
    {
        std::string m_res = a.str();
        m_res += b.str();
        return String(m_res.c_str());
    }

    /// are the two strings equal
    inline bool operator==(const String& a, const String& b)
    {
        return (a.str() == b.str());
    }

    /// are the two strings not equal
    inline bool operator!=(const String& a, const String& b)
    {
        return (a.str() != b.str());
    }

    /// is one string less than the other
    inline bool operator<(const String& a, const String& b)
    {
        return (a.str() < b.str());
    }

    /// gtest output
    void PrintTo(const System::String& str, ::std::ostream* os);
}

typedef System::String string;

using namespace System;

#endif
