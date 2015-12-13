
#include "gtest/gtest.h"

#include "System.h"
#include "System.Compiler.h"


using namespace System;

TEST(InternalTest, Compiler)
{
    System::Console::WriteLine(Compiler::Internals::CompilerName());
    EXPECT_TRUE(Compiler::Internals::CompilerName().Length()!=0);
}
