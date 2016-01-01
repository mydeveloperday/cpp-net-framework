// stub for Xml

#include "System/String.h"
#include "System/IO.h"
#include "System/Collections/Generic.h"

namespace System
{
namespace Xml
{
    
typedef enum { OpeningTag, ClosingTag, DataNode} XmlDataType;  

/// internal class used for parsing XML
class XmlToken
{
    String      m_data;
    XmlDataType m_type;
    
    public:
    XmlToken()
    {}
    
    XmlToken(const String &s,XmlDataType type):
        m_data(s),
        m_type(type)
    {}
    
    String ToString(XmlDataType t) const
    {
        switch(t){
            case OpeningTag: return "OpeningTag";
            case ClosingTag: return "ClosingTag";
            case DataNode: return "Data";
        }
        return "Unknown Type";
    }
    
    XmlDataType Type() const{
        return m_type;
    }
    
    String Data() const {
        return m_data;
    }
    
    String ToString() const {
        String s;
        
        s+="data=";
        s+=m_data;
        s+=", type=";
        s+=ToString(m_type);
        return s;
    }
};

/// XmlNode class
class XmlNode
{
    protected:
    List<XmlNode> m_Children;

    XmlNode *m_prev;
    XmlNode *m_next;

    String m_name;
    String m_value;

    public:
    XmlNode():
        m_prev(nullptr),
        m_next(nullptr)
    {
    }

    XmlNode LastChild()
    {
        return m_Children[m_Children.Count()-1];
    }
    
    void Name(const String &name)
    {
        m_name =  name;
    }
    
    String Name() const{
        return m_name;
    }
    
    void Value(const String &value)
    {
        m_value =  value;
    }
    
    String Value() const
    {
        return m_value;
    }
    
    void AppendChild(XmlNode &node)
    {
        m_Children.Add(node);
    }

    XmlNode FirstChild()
    {
        return m_Children[0];
    }

    bool HasChildNodes()
    {
        return !m_Children.Empty();
    }

    XmlNode PreviousSibling()
    {
        return *m_prev;
    }

    XmlNode NextSibling()
    {
        return *m_next;
    }
    
    List<XmlNode> ChildNodes()
    {
        return m_Children;
    }
};    
    
/// xml document class
class XmlDocument : public XmlNode
{
    public:
    /// Constructor
    XmlDocument()
    {}
    
    /// load the xml from a string
    void LoadXml(const System::String &str)
    {
        List<XmlToken> toks = LoadXmlParse(str);
        
        XmlNode &currentNode=(*this);
        int depth=0;
        for(size_t i=0;i<toks.Count();i++)
        {
            if (toks[i].Type()==OpeningTag){
                currentNode.Name(toks[i].Data());
                depth++;
            }
            if (toks[i].Type()==DataNode){
                XmlNode dataNode;
                dataNode.Value(toks[i].Data());
                currentNode.AppendChild(dataNode);
            }
            if (toks[i].Type()==ClosingTag){
                depth--;
            }
        }
        
        String str1;
        str1+="Children:";
        str1+=currentNode.ChildNodes().Count();
        
        System::Console::WriteLine(str1);
    }   
    
    List<XmlToken> LoadXmlParse(const System::String &str)
    {
        List<XmlToken> dataElements;
        
        bool in_xml_tag=false;
        
        StringBuilder currentData;
        XmlDataType   currentType=OpeningTag;
        
        char lastc = '\0';
        for(size_t i=0;i<str.Length();i++)
        {
            char c = str[i];
            
            if (c=='<'){
                in_xml_tag=true;
                if (!String::IsNullOrEmpty(currentData.ToString())){
                    dataElements.Add(XmlToken(currentData.ToString(),currentType));
                    currentData.Clear();
                }
                currentType=OpeningTag;
                lastc=c;
                continue;
            }
            
            if (c=='>'){
                in_xml_tag=false;
                dataElements.Add(XmlToken(currentData.ToString(),currentType));
                currentData.Clear();
                currentType=DataNode;
                lastc=c;
                continue;
            }
            
            if (c=='/'){
                if (lastc=='<'){
                    currentType=ClosingTag;
                    lastc=c;
                    continue;
                }
            }
            
            currentData.Append(c);
            lastc=c;
        }
        
        if (!String::IsNullOrEmpty(currentData.ToString()))
        {
            dataElements.Add(XmlToken(currentData.ToString(),currentType));
        }
        return dataElements;
    }

    XmlNode DocumentElement()
    {
        return m_Children[0];
    }
};



}
}

using namespace System::Xml;

