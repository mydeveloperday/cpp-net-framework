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

        static int Abs(int abs){
            if (abs<0){
                return -abs;
            }
            return abs;
        }

        static double Abs(double abs){
            if (abs<0){
                return -abs;
            }
            return abs;
        }

        static int Sign(int val){
            if (val<0){
                return -1;
            }
            if (val>0){
                return 1;
            }
            return 0;
        }

        static int Sign(double val){
            if (val<0){
                return -1;
            }
            if (val>0){
                return 1;
            }
            return 0;
        }

        static double Round(double val) 
        {
            return static_cast<double>(static_cast<int>(val+0.5));
        }
    };
}

using namespace System;

#endif
