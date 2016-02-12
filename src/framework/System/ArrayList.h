#ifndef _INCLUDED_SYSTEM_ARRAYLIST_H_
#define _INCLUDED_SYSTEM_ARRAYLIST_H_

#include <vector>

#include "System/String.h"
#include "System/Object.h"
#include "System/Collections/Generic.h"
#include "OS.h"

#include "pragmas.h"

namespace System
{
    namespace Collections
    {

    /// Array class
    class ArrayList : public ICollection
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

        /// add a range of objects into the array
        void AddRange(const List<Object>& c)
        {
            for(int i=0;i<c.Count();i++){
                Add(c[i]);
            }
        }

        /// add a range of objects into the array
        void AddRange(const List<String>& c)
        {
            for(int i=0;i<c.Count();i++){
                Add(c[i]);
            }
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

        // Trim the capacity to the number of items
        void TrimToSize()
        {
            // no real implementation needed here yet
        }

        void Reverse()
        {
        }

        void Sort()
        {
        }

        void SetRange(int index,const ICollection& c)
        {
            static_cast<void>(index);
            static_cast<void>(c);
        }

        void RemoveRange(int index,int count)
        {
            static_cast<void>(index);
            static_cast<void>(count);
        }

        void RemoteAt(int index)
        {
            static_cast<void>(index);
        }

        void Remove(const Object &obj)
        {
            static_cast<void>(obj);
        }

        int IndexOf(const Object &obj)
        {
            static_cast<void>(obj);
            return -1;
        }
        
        bool Contains(const Object& obj)
        {
            static_cast<void>(obj);
            return false;
        }

        void Insert(int index,const Object &obj)
        {
            static_cast<void>(obj);
        }

        void InsertRange(int index,const ICollection &c)
        {
            static_cast<void>(index);
            static_cast<void>(c);
        }
    };
    }
}

using namespace System;
using namespace System::Collections;

#endif
