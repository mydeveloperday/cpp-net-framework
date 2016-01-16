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
        static bool IsLetter(char ch){
            return isalpha(ch);
        } 
        static bool IsDigit(char ch){
            return isdigit(ch);
        } 
        static bool IsLetterOrDigit(char ch){
            return IsLetter(ch) || IsDigit(ch);
        } 
        static bool IsWhiteSpace(char ch){
            return isspace(ch);
        } 
        static bool IsPunctuation(char ch){
            return ispunct(ch);
        } 
    };
}

using namespace System;

#endif
