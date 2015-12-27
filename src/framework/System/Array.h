#ifndef _INCLUDED_SYSTEM_COLLECTIONS_GENERIC_H_
#define _INCLUDED_SYSTEM_COLLECTIONS_GENERIC_H_

#include <vector>

#include "System/String.h"
#include "OS.h"
#include "System/Exception.h"
#include "System/DateTime.h"
#include "System/Environment.h"

#include "pragmas.h"

namespace System
{
    /// Array class
    template <class T> class Array
    {
        std::vector<T> m_vec;

    public:
        /// Constructor
        Array()
        {
        }

        /// get the length of the array
        int Length() const
        {
            return static_cast<int>(m_vec.size());
        }

        /// get the nth item from the array
        const T& operator[](int index) const
        {
            return m_vec[index];
        }

        /// add an item into the array
        void Add(const T& item)
        {
            m_vec.push_back(item);
        }
    };
}

using namespace System;

#endif
