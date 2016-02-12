#ifndef _INCLUDED_SYSTEM_CHAR_H_
#define _INCLUDED_SYSTEM_CHAR_H_

#include "System/String.h"
#include <cctype>

namespace System
{
    /// a utility class for character based operations
    class Char
    {
    public:
        /// is this character is a letter
        static bool IsLetter(char ch)
        {
            return isalpha(ch)?true:false;
        }

        /// is the character a digit
        static bool IsDigit(char ch)
        {
            return isdigit(ch)?true:false;
        }

        /// is the character a digit or letter
        static bool IsLetterOrDigit(char ch)
        {
            return IsLetter(ch) || IsDigit(ch);
        }

        /// is the the character a whitespace
        static bool IsWhiteSpace(char ch)
        {
            return isspace(ch)?true:false;
        }

        /// is the character a punctuation character
        static bool IsPunctuation(char ch)
        {
            return ispunct(ch)?true:false;
        }
    };
}

using namespace System;

#endif
