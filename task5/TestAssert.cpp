#include "TestAssert.h"

void assert_true(bool condition, const char* message, const char* filename, int linenumber)
{
    if (!condition)
    {
		std::stringstream mesg;
		mesg << "Assertion failed: ";
		mesg << message;
		mesg << " at ";
		mesg << filename;
		mesg << ":";
		mesg << linenumber;
		throw new AssertException(mesg.str());
    }
}

