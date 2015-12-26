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
