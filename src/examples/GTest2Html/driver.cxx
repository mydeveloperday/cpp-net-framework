#include "System.h"

#include "main.h"

/// App driver
int main(int argc,char **argv)
{
    static_cast<void>(argc);
    static_cast<void>(argv);

    Array<System::String> args;

    // C# args are 1 based (no argv[0] of programme name)
    for (int i=1;i<argc;i++){
        args.Add(System::String(argv[i]));
    }

    ConsoleApplication1::Program::Main(args);

    return 0;
}


