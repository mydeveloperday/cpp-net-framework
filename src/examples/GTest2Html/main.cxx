#include "System.h"
#include "System.IO.h"
#include "System.Collections.Generic.h"

namespace ConsoleApplication1
{
    class Program
    {
    public:
        static void Main(Array<String> args)
        {
            if (args.Length() != 2) {
                System::Console::WriteLine(
                    "Usage: GTest2Html <intput.txt> <output.html>");
                return;
            }
            StreamWriter sw(args[1]);
            {
                sw.WriteLine("<html>");
                sw.WriteLine("<body>");
                StreamReader sr(args[0]);
                {
                    while (!sr.EndOfStream()) {
                        String s = sr.ReadLine();
                        System::Console::WriteLine(s);
                        sw.WriteLine(s);
                        sw.WriteLine("<br>");
                    }
                    sr.Dispose();
                }
                sw.WriteLine("</body>");
                sw.WriteLine("</html>");
                sw.Dispose();
            }
        }
    };
}
