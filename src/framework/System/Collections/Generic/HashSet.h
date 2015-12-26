#ifndef _INCLUDED_SYSTEM_COLLECTIONS_GENERIC_HASHSET_H_
#define _INCLUDED_SYSTEM_COLLECTIONS_GENERIC_HASHSET_H_

#include <map>

#include "pragmas.h"

namespace System
{
    namespace Collections
    {
        namespace Generic
        {
            /// a generic hashset class
            template <class K> class HashSet
            {
                std::map<K,bool> m_map;
                typedef typename std::map<K,bool>::const_iterator it_type;

            public:
                /// constructor
                HashSet()
                {
                }

                /// the size of the hashset
                int Count() const
                {
                    return static_cast<int>(m_map.size());
                }

                /// add a member to the hashset
				void Add(const K & key)
				{
					m_map[key]=true;
				}

                /// does the hashset contain a key
				bool Contains(const K& key) const
				{
					return m_map.find(key)!=m_map.end();
				}
                
                /// clear the hashset
                void Clear()
                {
                    m_map.clear();
                }
                
                /// remove an entry from the hashset
                void Remove(const K& key)
                {
                    m_map.erase(key);
                }
            };
        }
    }
}

using namespace System;
using namespace System::Collections::Generic;

#endif
