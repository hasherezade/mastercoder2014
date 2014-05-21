#ifndef TESTCASE_H_
#define TESTCASE_H_

#include "../atm_withdrawal_calculation_service_impl.h"
#include "../atm_resource_info_service_impl.h"
#include "assert_exception.h"

class TestCase {

public:
	TestCase(AtmResourceInfoService &testServ, Money &val, WithdrawalInfo& expectedOut);
	void run();

protected:
	AtmResourceInfoService &testServ;
	WithdrawalInfo& expectedOut;
	Money money;

	AtmWithdrawalCalculationServiceImpl calc;
	static void test(WithdrawalInfo &a, WithdrawalInfo &b);
};

#define TEST_CASE(v1, v2, v3) { TestCase test(v1, v2, v3); \
	try {test.run(); } \
	catch (AssertException *e) { \
	std::cout<< "[FAILED] "<<__FUNCTION__<<"\nFile: " << __FILE__  << std::endl;  throw e; } \
	std::cout<< "[+] "<<__FUNCTION__<< std::endl; \
}

#endif
