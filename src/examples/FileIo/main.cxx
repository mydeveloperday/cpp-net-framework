#include "System.h"
#include "System.IO.h"

namespace ConsoleApplication1
{
    class Program
    {
        public:
        static void Main(string* args)
        {
            FileInfo info = FileInfo("test.txt");

            if (!info.Exists()){ 
                System::Console::WriteLine("Does not exist");
            }

            {

               StreamWriter sr("test.txt");
               sr.WriteLine("This is just a test");
            }

            if (info.Exists()){ 
                System::Console::WriteLine("exist!");
            }
        }
    };
}



