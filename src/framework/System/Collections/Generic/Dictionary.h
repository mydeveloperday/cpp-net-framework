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
            /// a generic dicionary class
            template <class K, class V> class Dictionary
            {
                std::map<K, V> m_map;
                typedef typename std::map<K, V>::const_iterator it_type;

            public:
                /// constructor
                Dictionary()
                {
                }

                /// the size of the dictionary
                int Count() const
                {
                    return static_cast<int>(m_map.size());
                }

                /// look up an item via the key lookup (not a .NET call)
                const V& operator[](const K& key)
                {
                    return m_map[key];
                }

                /// const index lookup
                const V& operator[](const K& key) const
                {
                    it_type iter = m_map.find(key);
                    return iter->second;
                }

                /// add a member to the dictionary
                void Add(const K& key, const V& value)
                {
                    m_map[key] = value;
                }

                /// does the dictionary contain a key
                bool ContainsKey(const K& key) const
                {
                    return m_map.find(key) != m_map.end();
                }

                /// does the dictionary contain a value
                bool ContainsValue(const V& value) const
                {

                    for (it_type iter = m_map.begin(); iter != m_map.end();
                         iter++) {
                        if (iter->second == value) {
                            return true;
                        }
                    }
                    return false;
                }

                /// try and get the value from the dictionary
                bool TryGetValue(const K& key, V& value) const
                {
                    if (ContainsKey(key)) {
                        value = (*this)[key];
                        return true;
                    }
                    return false;
                }

                /// clear the dictionary
                void Clear()
                {
                    m_map.clear();
                }

                /// remove an entry from the dictionary
                void Remove(const K& key)
                {
                    m_map.erase(key);
                }
                
                it_type begin()
                {
                    return m_map.begin();
                }
                
                it_type end()
                {
                    return m_map.end();
                }
            };
        }
    }
}

using namespace System;
using namespace System::Collections::Generic;

#endif
