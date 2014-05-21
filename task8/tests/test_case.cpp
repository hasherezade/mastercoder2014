#include "test_case.h"

#include <iostream>     // std::cout
#include <stdio.h>
#include <vector>

using namespace std;

void TestCase::test(WithdrawalInfo &a, WithdrawalInfo &b)
{
	std::stringstream mesg;
	bool fail = false;
	if (a.isPossible() != b.isPossible()) {
		fail = true;
		mesg << "isPossible differs: ";
		mesg << a.isPossible() << "!=" << b.isPossible() << '\n';
		throw new AssertException(mesg.str());
	}
	if (a.isPossible()) {
		
		if (a.getWithdrawalBundle() == NULL || b.getWithdrawalBundle() == NULL) {
			mesg << "Withdrawal bundle is NULL";
			throw new AssertException(mesg.str());
		}
		vector<DenominationBundle>& vec1 = a.getWithdrawalBundle()->getDenominationBundle();
		vector<DenominationBundle>& vec2 = a.getWithdrawalBundle()->getDenominationBundle();

		if (vec1.size() != vec2.size()) {
			mesg << "Vector sizes differs: ";
			mesg << vec1.size() << "!=" << vec2.size() << '\n';
			throw new AssertException(mesg.str());
		}

		long vSize = vec1.size();
		for (long i = 0; i < vSize; i++ ) {
			DenominationBundle v1 = vec1[i];
			DenominationBundle v2 = vec2[i];

			if (v1.getDenomination() != v2.getDenomination()) {
				mesg << "DenominationBundle differs: ";
				mesg << "Denomination: "<< v1.getDenomination() << "!=" << v2.getDenomination();
				throw new AssertException(mesg.str());
			}
			if (v1.getAmount() != v2.getAmount()) {
				mesg << "DenominationBundle differs: ";
				mesg << "Denomination: "<< v1.getDenomination() << "!=" << v2.getDenomination();
				throw new AssertException(mesg.str());
			}
		}
		return;
	}

	if (a.getSuggestedWithdrawal()->getSmallerAmount().getAmount() != b.getSuggestedWithdrawal()->getSmallerAmount().getAmount()) {
		mesg << "Smaller differs: ";
		mesg << a.getSuggestedWithdrawal()->getSmallerAmount().getAmount() << "!=" << b.getSuggestedWithdrawal()->getSmallerAmount().getAmount();
		throw new AssertException(mesg.str());
	}
	if (a.getSuggestedWithdrawal()->getBiggerAmount().getAmount() != b.getSuggestedWithdrawal()->getBiggerAmount().getAmount()) {
		mesg << "Bigger differs: ";
		mesg << a.getSuggestedWithdrawal()->getBiggerAmount().getAmount() << "!=" << b.getSuggestedWithdrawal()->getBiggerAmount().getAmount();
		a.print();
		throw new AssertException(mesg.str());
	}
}

TestCase::TestCase(AtmResourceInfoService &v_testServ, Money &v_val, WithdrawalInfo& v_expectedOut)
	: testServ(v_testServ), expectedOut(v_expectedOut), money(v_val)
{
	calc.setAtmResourceInfoService(&testServ);
}

void TestCase::run()
{
	//std::cout <<"\nRequested: " << money << std::endl;
	WithdrawalInfo* out = calc.calculateWithdrawal(money);
	if (out == NULL) { 
		std::cout << "out is NULL\n";
		return;
	}
	//std::cout << money << endl;
	//out->print();
	test(*out, this->expectedOut);
}
