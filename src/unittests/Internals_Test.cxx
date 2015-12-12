
#include "gtest/gtest.h"

#include "System.h"


using namespace System;

TEST(InternalTest, Compiler)
{
    System::Console::WriteLine(Compiler::Internals::CompilerName());
}
