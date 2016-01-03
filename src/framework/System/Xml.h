// stub for Xml

#include "System/String.h"
#include "System/IO.h"
#include "System/Collections/Generic.h"

namespace System
{
namespace Xml
{
    
/// internal enumberation used for XML parsing
typedef enum { OpeningTag, ClosingTag, DataNode} XmlDataType;  

/// internal class used for parsing XML
class XmlToken
{
    String      m_data;
    XmlDataType m_type;
    
    public:
    /// the constructor
    XmlToken()
    {}
    
    /// constructor based on data and type
    XmlToken(const String &s,XmlDataType type):
        m_data(s),
        m_type(type)
    {}
    
    /// xmldatatype to string
    String ToString(XmlDataType t) const
    {
        switch(t){
            case OpeningTag: return "OpeningTag";
            case ClosingTag: return "ClosingTag";
            case DataNode: return "Data";
        }
        return "Unknown Type";
    }
    
    /// get the xml data type
    XmlDataType Type() const{
        return m_type;
    }
    
    /// gets the data of the token
    String Data() const {
        return m_data;
    }
    
    /// tostring converter
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
    /// the node sub children
    List<XmlNode> m_Children;

    /// the previous sibling
    XmlNode *m_prev;
    
    /// the next sibling
    XmlNode *m_next;

    /// the name of the node
    String m_name;
    
    /// the value of the node
    String m_value;

    public:
    /// Constructor for XmlNode
    XmlNode():
        m_prev(nullptr),
        m_next(nullptr)
    {
    }

    /// get the last child
    XmlNode LastChild()
    {
        return m_Children[m_Children.Count()-1];
    }
    
    /// set the name of the node
    void Name(const String &name)
    {
        m_name =  name;
    }
    
    /// get the name of the node
    String Name() const{
        return m_name;
    }
    
    /// set the value of the node
    void Value(const String &value)
    {
        m_value =  value;
    }
    
    /// get the value of the node
    String Value() const
    {
        return m_value;
    }
    
    /// append a child to the node
    void AppendChild(XmlNode &node)
    {
        m_Children.Add(node);
    }

    /// get the first child
    XmlNode FirstChild()
    {
        return m_Children[0];
    }

    /// does the node have child nodes
    bool HasChildNodes()
    {
        return !m_Children.Empty();
    }

    /// get the previous sibling
    XmlNode PreviousSibling()
    {
        return *m_prev;
    }

    /// get the next sibling
    XmlNode NextSibling()
    {
        return *m_next;
    }
    
    /// get the child nodes
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
        for(int i=0;i<toks.Count();i++)
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
    
    /// internal parse to XmlToken
    List<XmlToken> LoadXmlParse(const System::String &str)
    {
        List<XmlToken> dataElements;
        
        StringBuilder currentData;
        XmlDataType   currentType=OpeningTag;
        
        char lastc = '\0';
        for(int i=0;i<str.Length();i++)
        {
            char c = str[i];
            
            if (c=='<'){
                if (!String::IsNullOrEmpty(currentData.ToString())){
                    dataElements.Add(XmlToken(currentData.ToString(),currentType));
                    currentData.Clear();
                }
                currentType=OpeningTag;
                lastc=c;
                continue;
            }
            
            if (c=='>'){
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

    /// the document element
    XmlNode DocumentElement()
    {
        return m_Children[0];
    }
};



}
}

using namespace System::Xml;

