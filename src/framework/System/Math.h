#ifndef _INCLUDED_SYSTEM_MATH_H_
#define _INCLUDED_SYSTEM_MATH_H_

#include "pragmas.h"

namespace System
{
	/// A class for maths functions
    class Math
    {
    public:
        /// maximum integer function
        static int Max(int a,int b)
        {
            if (a < b ){
                return b;
            }
            return a;
        }
        
        /// minimum integer function
        static int Min(int a,int b)
        {
            if (a > b ){
                return b;
            }
            return a;
        }

        /// maximum double function
        static double Max(double a,double b)
        {
            if (a < b ){
                return b;
            }
            return a;
        }
        
        /// minimum double function
        static double Min(double a,double b)
        {
            if (a > b ){
                return b;
            }
            return a;
        }

        /// floor function for doubles always round down
        static double Floor(double a)
        {
            if (a > 0) {
                return static_cast<double>(static_cast<int>(a));
            }
            return static_cast<int>(static_cast<int>(a-1.0));
        }

        /// ceiling function always rounds up
        static int Ceiling(double a)
        {
            if (a>0){
                return static_cast<int>(static_cast<int>(a+1.0));
            }
            return static_cast<int>(static_cast<int>(a));
        }

        /// absolute integer function
        static int Abs(int abs){
            if (abs<0){
                return -abs;
            }
            return abs;
        }

        /// absolute double function
        static double Abs(double abs){
            if (abs<0){
                return -abs;
            }
            return abs;
        }

        /// returns the sign of the integer value
        static int Sign(int val){
            if (val<0){
                return -1;
            }
            if (val>0){
                return 1;
            }
            return 0;
        }

        /// returns the sign of the double value
        static int Sign(double val){
            if (val<0){
                return -1;
            }
            if (val>0){
                return 1;
            }
            return 0;
        }

        /// rounds the double up or down to the nearest value
        static double Round(double val) 
        {
            return static_cast<double>(static_cast<int>(val+0.5));
        }

        /// return the integer portions of a double value
        static int Truncate(double val) 
        {
            return static_cast<int>(val);
        }
    };
}

using namespace System;

#endif
