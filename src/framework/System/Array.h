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
    template <class T> class Array
    {
        std::vector<T> m_vec;

    public:
        Array()
        {
        }

        int Length() const
        {
            return static_cast<int>(m_vec.size());
        }

        const T& operator[](int index) const
        {
            return m_vec[index];
        }

        // private not part of .NET Framework
        void Add(const T& item)
        {
            m_vec.push_back(item);
        }
    };
}

using namespace System;

#endif
