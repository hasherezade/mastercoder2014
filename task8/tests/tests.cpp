#include "tests.h"

//using namespace test;

void emptyService()
{
	Money m(100);
	std::vector<DenominationBundle> dm;
	AtmResourceInfoServiceImpl testServ(dm);

	//output
	BanknoteBundle *v_bundle = NULL;
	SuggestedWithdrawal *v_withdrawal = new SuggestedWithdrawal(Money(0), Money(0));
	WithdrawalInfoImpl out(false, v_bundle, v_withdrawal);

	TEST_CASE(testServ, m, out);
}

void getFirstDenom()
{
	Money m(20);

	std::vector<DenominationBundle> dm;
	dm.push_back(DenominationBundle(Denomination(10), 2));
	dm.push_back(DenominationBundle(Denomination(100), 2));
	AtmResourceInfoServiceImpl testServ(dm);

	//output
	std::vector<DenominationBundle> dmOut;
	dmOut.push_back(DenominationBundle(Denomination(20), 1));

	BanknoteBundle *v_bundle = new BanknoteBundle(dmOut);
	SuggestedWithdrawal *v_withdrawal = NULL;
	WithdrawalInfoImpl out(true, v_bundle, v_withdrawal);

	TEST_CASE(testServ, m, out);
}

void getLastDenom()
{
	Money m(100);

	std::vector<DenominationBundle> dm;
	dm.push_back(DenominationBundle(Denomination(10), 2));
	dm.push_back(DenominationBundle(Denomination(100), 2));
	AtmResourceInfoServiceImpl testServ(dm);

	//output
	std::vector<DenominationBundle> dmOut;
	dmOut.push_back(DenominationBundle(Denomination(100), 1));

	BanknoteBundle *v_bundle = new BanknoteBundle(dmOut);
	SuggestedWithdrawal *v_withdrawal = NULL;
	WithdrawalInfoImpl out(true, v_bundle, v_withdrawal);

	TEST_CASE(testServ, m, out);
}

void sugestSimple()
{
	Money m(120);

	std::vector<DenominationBundle> dm;
	dm.push_back(DenominationBundle(Denomination(10), 1));
	dm.push_back(DenominationBundle(Denomination(100), 2));
	dm.push_back(DenominationBundle(Denomination(200), 2));
	AtmResourceInfoServiceImpl testServ(dm);

	//output
	BanknoteBundle *v_bundle = NULL;
	SuggestedWithdrawal *v_withdrawal = new SuggestedWithdrawal(Money(110), Money(200));
	WithdrawalInfoImpl out(false, v_bundle, v_withdrawal);

	TEST_CASE(testServ, m, out);
}

void sugestWhenOutOfCapacity()
{
	Money m(1000);

	std::vector<DenominationBundle> dm;
	dm.push_back(DenominationBundle(Denomination(100), 1));
	dm.push_back(DenominationBundle(Denomination(50), 4));
	dm.push_back(DenominationBundle(Denomination(20), 5));
	dm.push_back(DenominationBundle(Denomination(10), 4));
	dm.push_back(DenominationBundle(Denomination(200), 0));
	dm.push_back(DenominationBundle(Denomination(500), 1));
	AtmResourceInfoServiceImpl testServ(dm);

	//output
	BanknoteBundle *v_bundle = NULL;
	SuggestedWithdrawal *v_withdrawal = new SuggestedWithdrawal(Money(940), Money(0));
	WithdrawalInfoImpl out(false, v_bundle, v_withdrawal);

	TEST_CASE(testServ, m, out);
}

void sugestWhenOneEmptied()
{
	Money m(51);

	std::vector<DenominationBundle> dm;
	dm.push_back(DenominationBundle(Denomination(100), 2));
	dm.push_back(DenominationBundle(Denomination(20), 2));
	dm.push_back(DenominationBundle(Denomination(5), 3));
	AtmResourceInfoServiceImpl testServ(dm);

	//output
	BanknoteBundle *v_bundle = NULL;
	SuggestedWithdrawal *v_withdrawal = new SuggestedWithdrawal(Money(50), Money(55));
	WithdrawalInfoImpl out(false, v_bundle, v_withdrawal);

	TEST_CASE(testServ, m, out);
}

void sugestWhenTooSmall()
{
	Money m(1);

	std::vector<DenominationBundle> dm;
	dm.push_back(DenominationBundle(Denomination(100), 2));
	dm.push_back(DenominationBundle(Denomination(20), 2));
	dm.push_back(DenominationBundle(Denomination(5), 3));
	AtmResourceInfoServiceImpl testServ(dm);

	//output
	BanknoteBundle *v_bundle = NULL;
	SuggestedWithdrawal *v_withdrawal = new SuggestedWithdrawal(Money(0), Money(5));
	WithdrawalInfoImpl out(false, v_bundle, v_withdrawal);

	TEST_CASE(testServ, m, out);
}


void tricky60()
{
	Money m(60);

	std::vector<DenominationBundle> dm;
	dm.push_back(DenominationBundle(Denomination(20), 3));
	dm.push_back(DenominationBundle(Denomination(50), 1));
	dm.push_back(DenominationBundle(Denomination(100), 1));
	AtmResourceInfoServiceImpl testServ(dm);

	//output
	std::vector<DenominationBundle> dmOut;
	dmOut.push_back(DenominationBundle(Denomination(20), 3));

	BanknoteBundle *v_bundle = new BanknoteBundle(dmOut);
	SuggestedWithdrawal *v_withdrawal = NULL;
	WithdrawalInfoImpl out(true, v_bundle, v_withdrawal);

	TEST_CASE(testServ, m, out);
}

void tricky160()
{
	Money m(100);

	std::vector<DenominationBundle> dm;
	dm.push_back(DenominationBundle(Denomination(20), 3));
	dm.push_back(DenominationBundle(Denomination(50), 3));
	dm.push_back(DenominationBundle(Denomination(1), 10));
	AtmResourceInfoServiceImpl testServ(dm);

	//output
	std::vector<DenominationBundle> dmOut;
	dmOut.push_back(DenominationBundle(Denomination(20), 3));
	dmOut.push_back(DenominationBundle(Denomination(50), 2));

	BanknoteBundle *v_bundle = new BanknoteBundle(dmOut);
	SuggestedWithdrawal *v_withdrawal = NULL;
	WithdrawalInfoImpl out(true, v_bundle, v_withdrawal);

	TEST_CASE(testServ, m, out);
}

void printTest()
{
	std::vector<DenominationBundle> dm;

	dm.push_back(DenominationBundle(Denomination(20), 3));
	dm.push_back(DenominationBundle(Denomination(50), 3));
	dm.push_back(DenominationBundle(Denomination(1), 10));

	std::cout << "------------------"<< std::endl;
	for (int i = 0; i < dm.size(); i++) {
		if (dm[i].getAmount() != 0) {
			std::cout << "[" <<  i << "] "<< dm[i].getDenomination() << " : " << dm[i].getAmount() << '\n';
		}
	} 
	
	AtmResourceInfoServiceImpl testServ(dm);
	
	AtmWithdrawalCalculationServiceImpl calc;
	calc.setAtmResourceInfoService(&testServ);

	long long val = 0;
	std::cout <<"Get: ";
	std::cin >> val;
	Money m(val);

	//output
	std::vector<DenominationBundle> dmOut;
	dmOut.push_back(DenominationBundle(Denomination(100), 1));

	BanknoteBundle *v_bundle = new BanknoteBundle(dmOut);

	SuggestedWithdrawal *v_withdrawal = NULL;
	WithdrawalInfoImpl out(true, v_bundle, v_withdrawal);

	WithdrawalInfo *wInfo = calc.calculateWithdrawal(m);
	if (wInfo != NULL) wInfo->print();
}
