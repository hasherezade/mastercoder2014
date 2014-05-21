#include "TextDistanceServiceTest.h"
#include "TestCase.h"

#include <iostream>

#ifdef _WINDOWS
#include <Windows.h>
#endif

int main(int argc, char *argv[])
{
	TextDistanceServiceTest runner;
    try
    {
		runner.setUp();
    }
    catch(AssertException* e)
    {
		std::cout<< "Error on set up" << std::endl;
		return 1;
    }
    try
    {
		runner.testJaroWinker();
		runner.testLevenstein();
    }
    catch(AssertException* e)
    {
		std::cout << e->what() << "\n";
    }
	
#ifdef _WINDOWS
	system("pause");
#endif
	return 0;
}
