#ifndef _INCLUDED_SYSTEM_ARRAYLIST_H_
#define _INCLUDED_SYSTEM_ARRAYLIST_H_

#include <vector>

#include "System/String.h"
#include "System/Object.h"
#include "OS.h"

#include "pragmas.h"

namespace System
{
    namespace Collections
    {

    /// Array class
    class ArrayList
    {
        std::vector<Object> m_vec;

    public:
        /// Constructor
        ArrayList()
        {
        }

        /// get the length of the array
        int Length() const
        {
            return static_cast<int>(m_vec.size());
        }

        /// get the nth item from the array
        const Object& operator[](int index) const
        {
            return m_vec[index];
        }

        /// add an item into the array
        void Add(const Object& item)
        {
            m_vec.push_back(item);
        }

        // Removes all elements from the ArrayList
        void Clear()
        {
            m_vec.clear();
        }

        /// Creates a shallow copy of the ArrayList
        ArrayList Clone()
        {
            ArrayList copy;
            for(size_t i=0;i<m_vec.size();i++)
            {
                copy.Add(m_vec[i]);
            }
            return copy;
        }
    };
    }
}

using namespace System;
using namespace System::Collections;

#endif
