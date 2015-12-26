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
                typedef typename std::map<K,V>::const_iterator it_type;

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

				bool ContainsKey(const K& key) const
				{
					return m_map.find(key)!=m_map.end();
				}
                
                bool ContainsValue(const V& value) const
				{
                    
					for(it_type iter = m_map.begin();
                        iter!=m_map.end();iter++)
                    {
                        if (iter->second==value){
                            return true;
                        } 
                    }
                    return false;
				}
                
                void Clear()
                {
                    m_map.clear();
                }
                
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
