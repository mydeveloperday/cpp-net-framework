#ifndef _INCLUDED_SYSTEM_MATH_H_
#define _INCLUDED_SYSTEM_MATH_H_

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

        static double Floor(double a)
        {
            return static_cast<double>(static_cast<int>(a));
        }
    };
}

using namespace System;

#endif
