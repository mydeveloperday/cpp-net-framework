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
            template <class T> class List : public ICollection
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
                    return (Count() == 0);
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
                
                Array<T> ToArray()
                {
                    Array<T> array;
                    
                    for(size_t i=0;i<m_vec.size();i++){
                        array.Add((*this)[i]);
                    }
                    
                    return array;
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
                
                typename std::vector<T>::iterator begin()
                {
                    return m_vec.begin();
                }
                
                typename std::vector<T>::iterator end()
                {
                    return m_vec.end();
                }
            };
        }
    }
}

using namespace System;
using namespace System::Collections::Generic;

#endif
