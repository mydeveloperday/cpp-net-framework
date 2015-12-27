#include "System.h"
#include "System/IO.h"
#include "System/Collections/Generic.h"

namespace ConsoleApplication1
{
    class Program
    {
    public:
        static void Main(Array<String> args)
        {
            if (args.Length() != 2) {
                System::Console::WriteLine(
                    "Usage: CSharpToCpp <intput.cs> <output.cxx>");
                return;
            }

            List<String> lines;
            try {
                StreamReader sr(args[0]);
                {
                    while (!sr.EndOfStream()) {
                        String s = sr.ReadLine();
                        s = s.Replace("\r\n","\n");
                        String ns = TransformLine(s);
                        lines.Add(ns);
                    }
                    sr.Dispose();
                }

                StreamWriter sw(args[1]);
                {
                    for (int i = 0; i < lines.Count(); i++) {
                        sw.WriteLine(lines[i]);
                    }
                    sw.Dispose();
                }
            } catch (const Exception& e) {
                System::Console::WriteLine(e.Message());
            }
        }

        static String TransformLine(const String& s)
        {
            String ns = s;
            if (s.Contains("System.Console.Write")) {
                ns =
                    ns.Replace("System.Console.Write", "System::Console::Write");
            }
            if (s.Contains("Console.Write")) {
                ns =
                    ns.Replace("Console.Write", "Console::Write");
            }
            if (s.Contains("string[]")){
                ns = ns.Replace("string[]", "Array<String>");
            }
            if (s.StartsWith("using ")){
                ns = ns.Replace("using ","#include \"");
                ns = ns.Replace(".","/");
                ns = ns.Replace(";",".h\"");
            }
            if (s.Contains(".Length")){
                ns = ns.Replace(".Length",".Length()");
            }
            if (s.Contains(".Message")){
                ns = ns.Replace(".Message",".Message()");
            }
            if (s.Contains("Path.")){
                ns = ns.Replace("Path.","Path::");
            }
            if (s.Contains("Program.")){
                ns = ns.Replace("Program.","Program::");
            }
            if (s.Contains("= new "))
            {
                ns = ns.Replace("= new ",";// = new ");
            }
            if (s.Contains("Environment.")){
                ns = ns.Replace("Environment.","Environment::");
            }
            if (s.Contains("StringComparison.")){
                ns = ns.Replace("StringComparison.","StringComparison::");
            }
            if (s.Contains("System.IO.")) {
                ns = ns.Replace("System.IO.", "System::IO::");
            }
            if (s.Contains("private void")) {
                // TODO add a private: line before if not in private section
                ns = ns.Replace("private void", "void");
            }
            if (s.Contains("public void")) {
                // TODO add a public: line before if not in private section
                ns = ns.Replace("public void", "void");
            }
            if (s.Contains("public void")) {
                // TODO add a public: line before if not in private section
                ns = ns.Replace("public void", "void");
            }
            if (s.Contains("public static")) {
                // TODO add a public: line before if not in private section
                ns = ns.Replace("public static", "static");
            }
            if (s.Trim().StartsWith("namespace ")) {
                if (s.Contains(".")) {
                    ns = ns.Replace(".", "_");
                }
            }

            // handle whitespace variants
            if (s.Contains("{ get; set; }")) {
                ns = ns.Replace("{ get; set; }", ";");
            }

            if (s.Contains(" : I")) {
                ns = ns.Replace(" : I", ": public I");
            }

            if (s.Contains("public interface")) {
                ns = ns.Replace("public interface", "class");
            }

            if (s.Contains("public class")) {
                ns = ns.Replace("public class", "class");
            }

            if (s.Contains("internal class")) {
                ns = ns.Replace("internal class", "class");
            }
            if (s.Trim().StartsWith("foreach(var ")) {
                ns = ns.Replace("foreach(var ", "for(auto ");
                ns = ns.Replace("in ", " : ");
            }
            return ns;
        }
    };
}
