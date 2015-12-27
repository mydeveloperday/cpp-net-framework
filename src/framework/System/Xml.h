// stub for Xml

#include "System/String.h"
#include "System/IO.h"

/// xml document class
namespace System
{
namespace Xml
{
class XmlDocument
{
    public:

    /// Constructor
    XmlDocument()
    {}

    /// load the xml from a string
    void LoadXml(const System::String &str)
    {
        static_cast<void>(str);
    }
};
}
}

using namespace System::Xml;

