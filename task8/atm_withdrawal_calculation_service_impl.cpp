#include "atm_withdrawal_calculation_service_impl.h"

#include <algorithm>
#include <iostream>     // std::cout

#define DEBUG 0

//--------------------------------------------------------------------------------


void PropSol::append(DenominationBundle got)
{
	const int amt = got.getAmount();
	if (amt == 0) return;
	solVec.push_back(got);
	pieces += amt;
}

unsigned long long PropSol::totalValue()
{
	long long total = 0;
	std::vector<DenominationBundle>::iterator itr;
	for (itr = solVec.begin(); itr != solVec.end(); itr++) {
		DenominationBundle& den = *itr;
		den.bundleVal();
		total += den.bundleVal();
	}
	return total;
}
//--------------------------------------------------------------------------------

void AtmWithdrawalCalculationServiceImpl::resetHelpers()
{
	std::map<unsigned long long, PropSol*>::iterator itr;
	for (itr = minPossibleSols.begin(); itr != minPossibleSols.end(); itr++) {
		delete itr->second;
	}
	minPossibleSols.clear();
}

void AtmWithdrawalCalculationServiceImpl::setAtmResourceInfoService(AtmResourceInfoService *service) 
{
	if (service == NULL) return;

	std::vector<DenominationBundle> &vec = service->getAtmResoures()->getDenominationBundle();
	std::sort(vec.begin(), vec.end());

	m_atmResourceInfoService = service;
}


PropSol *AtmWithdrawalCalculationServiceImpl::calculateProposal(unsigned long long val,
	std::vector<DenominationBundle> &vec,
	std::vector<DenominationBundle>::iterator seekBegin, 
	std::vector<DenominationBundle>::iterator seekEnd
	)
{
	PropSol *proposedSol = NULL; //new PropSol();
	std::set<long> excludedIndexes;
	std::set<unsigned long long> excludedDenoms;
	std::set<unsigned long long> usedDenoms;

	while (val) {
		seekEnd = std::upper_bound(seekBegin, seekEnd, val);
		if (seekBegin >= seekEnd) return proposedSol;

		long next = (seekEnd - seekBegin); // index of first bigger
		long index = next - 1; // index of last not bigger
		if (index < 0) return proposedSol;
		if (excludedIndexes.find(index) != excludedIndexes.end()) {
			seekEnd--;
			continue;
		}

		DenominationBundle &bundle = vec[index];
		
		const unsigned long long BUNDLE_DENOM = bundle.getDenomination();
		const unsigned long long BUNDLE_AMT = bundle.getAmount();
		
		unsigned long long needAmt = val / BUNDLE_DENOM;
		unsigned long long canGetAmt = (BUNDLE_AMT < needAmt) ? BUNDLE_AMT : needAmt;
		if (canGetAmt == 0) {
			seekEnd--;
			continue;
		}
		if (canGetAmt > 0) {
			if (proposedSol == NULL) proposedSol = new PropSol();

			proposedSol->append(DenominationBundle(Denomination(BUNDLE_DENOM), canGetAmt));
			if (canGetAmt == BUNDLE_AMT) excludedIndexes.insert(index);
			usedDenoms.insert(BUNDLE_DENOM);
		}

		unsigned long long gotVal = canGetAmt * BUNDLE_DENOM;
		val -= gotVal;

		PropSol* stored = this->minPossibleSols[val];
		bool isOk = true;
		if (stored != NULL) {
			
			std::vector<DenominationBundle>::iterator itr;
			for (itr = stored->solVec.begin(); itr != stored->solVec.end(); itr++) {
				DenominationBundle &b = *itr;
				if (usedDenoms.find(b.getDenomination()) != usedDenoms.end()) {
					//std::cout <<"Already checked:" << b.getDenomination() <<"\n";
					isOk = false;
					stored = NULL;
					break;
				}
			}
		}
		if (stored != NULL)  {
			std::vector<DenominationBundle>::iterator itr;
			//std::cout <<"Already checked:" << b.getDenomination() <<"\n";

			for (itr = stored->solVec.begin(); itr != stored->solVec.end(); itr++) {
				proposedSol->append(*itr);
			}
			return proposedSol;
		}
	}

    return proposedSol;
}

PropSol* AtmWithdrawalCalculationServiceImpl::findMinPossible(unsigned long long demandedVal, std::vector<DenominationBundle> &vec)
{
	PropSol *minPossible = NULL;

	unsigned long long val = demandedVal;
	std::vector<DenominationBundle>::iterator seekBegin = vec.begin();
	std::vector<DenominationBundle>::iterator seekEnd = vec.end();

	for(;seekBegin < seekEnd; seekEnd--) {
		PropSol *p = calculateProposal(val, vec, seekBegin, seekEnd);
		if (p == NULL) break;
		unsigned long long missing = val - p->totalValue();
		if (missing == 0) {
			if (minPossible == NULL || minPossible->getPieces() > p->getPieces()) {
				delete minPossible;
				minPossible = p;
			}
		}
	}
	return minPossible;
}

WithdrawalInfo* AtmWithdrawalCalculationServiceImpl::calculateWithdrawal(const Money &m)
{
	resetHelpers();
	if (m_atmResourceInfoService == NULL) {
		std::cerr << "Service is NULL";
		return NULL; // TODO: throw exception
	}
	BanknoteBundle *bundle = this->m_atmResourceInfoService->getAtmResoures();
	std::vector<DenominationBundle> &vec = bundle->getDenominationBundle(); // wektor nominalow i ich ilosci
	const size_t vecSize = vec.size();
	unsigned long long demandedVal = m.getAmount();

	PropSol *minPossible = NULL;
	unsigned long long last = 0;

	unsigned long long smaller = 0;
	unsigned long long bigger = 0;

	std::set<unsigned long long> possibleVals;
	const unsigned long long MAX = bundle->getTotalVal();

	bool stop = false;

	for (unsigned long long  i = 1; stop == false && i <= MAX; i++) {
		
		minPossible = findMinPossible(i, vec);
		if (minPossible != NULL) {
			if (i >= demandedVal) {
				stop = true;
				bigger = i;
			} else smaller = i;

			this->minPossibleSols[i] = minPossible;
			possibleVals.insert(i);
			last = i;
		}
	}
	//prepare output:
	minPossible = this->minPossibleSols[demandedVal];
	unsigned long long gotVal = demandedVal;

	bool v_possible = (minPossible != NULL);
	BanknoteBundle* v_bundle = NULL;
	SuggestedWithdrawal* v_withdrawal = NULL;

	if (v_possible) {
		v_bundle = new BanknoteBundle(minPossible->solVec);
	} else {
		v_withdrawal = new SuggestedWithdrawal(Money(smaller), Money(bigger));
	}

	WithdrawalInfo* info = new WithdrawalInfoImpl(v_possible, v_bundle, v_withdrawal);
	return info;
}
