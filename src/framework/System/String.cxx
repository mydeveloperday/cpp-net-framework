
#include "String.h"

String String::Format(const String &fmt,const Object &a)
{
    String output;

    output=fmt;

    output = output.Replace("{0}",a.ToString());

    return output;
}


String String::Format(const char* fmt,const char* a)
{
    return Format(String(fmt),String(a));
}
