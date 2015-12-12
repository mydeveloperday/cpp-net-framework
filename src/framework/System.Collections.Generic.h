#ifndef _INCLUDED_SYSTEM_COLLECTIONS_GENERIC_H_
#define _INCLUDED_SYSTEM_COLLECTIONS_GENERIC_H_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#include "NetString.h"
#include "OS.h"
#include "Exception.h"
#include "DateTime.h"
#include "Environment.h"

#include "pragmas.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            template <class T> class List
            {
                std::vector<T> m_vec;

            public:
                List()
                {
                }

                int Count() const
                {
                    return static_cast<int>(m_vec.size());
                }

                const T& operator[](int index) const
                {
                    return m_vec[index];
                }

                void Add(const T& t)
                {
                    m_vec.push_back(t);
                }
            };

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

            template <class K,class V> class Dictionary
            {
                std::map<K,V> m_map;

            public:
                Dictionary()
                {
                }

                int Count() const
                {
                    return static_cast<int>(m_map.size());
                }

                const V& operator[](K key) const
                {
                    return m_map[key];
                }
            };
        }
    }
}

using namespace System;
using namespace System::Collections::Generic;

#endif
