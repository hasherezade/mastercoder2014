#include "withdrawal_info_impl.h"
#include <iostream>     // std::cout

using namespace std;
void WithdrawalInfoImpl::print()
{
	std::cout << "----\n";
	if (this->possible == false) {
		std::cout << "NOT POSSIBLE!\n";
		std::cout << "Get smaller: "<< this->getSuggestedWithdrawal()->getSmallerAmount().getAmount() <<'\n';
		std::cout << "Get bigger: "<< this->getSuggestedWithdrawal()->getBiggerAmount().getAmount() << std::endl;
	} else {

		std::cout << "POSSIBLE!\n";
		vector<DenominationBundle>& vec = this->bundle->getDenominationBundle();
		vector<DenominationBundle>::iterator itr;
	
		for (itr = vec.begin(); itr != vec.end(); itr++) {
			DenominationBundle &db = *itr;
			std::cout << db.getDenomination() << " : " << db.getAmount() << '\n';
		}
	}	
	std::cout << "------------------\n"<< endl;
}

