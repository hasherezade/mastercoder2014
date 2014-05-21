#include <iostream>     // std::cout
#include <stdio.h>
#include "atm_withdrawal_calculation_service_impl.h"
#include "atm_resource_info_service_impl.h"
#include "tests/tests.h"

#include <vector>
#include <algorithm>

int main()
{
	try {
		emptyService();
		getFirstDenom();
		getLastDenom();
		
		sugestWhenOneEmptied();
		sugestWhenTooSmall();
		tricky60();
		sugestWhenOutOfCapacity();
		tricky160();
		sugestSimple();

	} catch(AssertException* e) {
		std::cout << e->what() <<"\n";
    }
	/*
	while (true) {
		printTest();
	}*/
	return 0;
}