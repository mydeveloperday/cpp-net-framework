#ifndef _INCLUDED_SYSTEM_COLLECTIONS_GENERIC_LIST_H_
#define _INCLUDED_SYSTEM_COLLECTIONS_GENERIC_LIST_H_

#include <vector>

#include "System/String.h"
#include "OS.h"
#include "System/Exception.h"
#include "System/DateTime.h"
#include "System/Environment.h"

#include "pragmas.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            /// a generalized list class
            template <class T> class List
            {
                std::vector<T> m_vec;

            public:
                /// the constuctor
                List()
                {
                }

                /// the number of elements in the list
                int Count() const
                {
                    return static_cast<int>(m_vec.size());
                }
                
                /// is the list empty
                bool Empty() const
                {
                    return (Count()==0);
                }

                /// the index operator lookup
                const T& operator[](int index) const
                {
                    return m_vec[index];
                }

                /// add an element to the list
                void Add(const T& t)
                {
                    m_vec.push_back(t);
                }
                
                /// clear the contents of the list
                void Clear()
                {
                    m_vec.clear();
                }
            };
        }
    }
}

using namespace System;
using namespace System::Collections::Generic;

#endif
