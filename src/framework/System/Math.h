#ifndef _INCLUDED_SYSTEM_MATH_H_
#define _INCLUDED_SYSTEM_MATH_H_

#include "System/String.h"
#include "OS.h"

#include "System/Exception.h"
#include "System/DateTime.h"
#include "System/Environment.h"

#include "pragmas.h"

namespace System
{
    class Math
    {
    public:

        static int Max(int a,int b)
        {
            if (a < b ){
                return b;
            }
            return a;
        }
        static int Min(int a,int b)
        {
            if (a > b ){
                return b;
            }
            return a;
        }

        static double Max(double a,double b)
        {
            if (a < b ){
                return b;
            }
            return a;
        }
        static double Min(double a,double b)
        {
            if (a > b ){
                return b;
            }
            return a;
        }
    };
}

using namespace System;

#endif
