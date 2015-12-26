#ifndef _INCLUDED_SYSTEM_COLLECTIONS_GENERIC_DICTIONARY_H_
#define _INCLUDED_SYSTEM_COLLECTIONS_GENERIC_DICTIONARY_H_

#include <map>

#include "pragmas.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
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

                const V& operator[](const K & key)
                {
                    return m_map[key];
                }

				void Add(const K& key,const V & value)
				{
					m_map[key]=value;
				}

				bool ContainsKey(const K& key)
				{
					return m_map.find(key)!=m_map.end();
				}
            };
        }
    }
}

using namespace System;
using namespace System::Collections::Generic;

#endif
