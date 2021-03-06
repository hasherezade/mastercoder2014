#ifndef ATM_WITHDRAWAL_CALCULATION_SERVICE_IMPL
#define ATM_WITHDRAWAL_CALCULATION_SERVICE_IMPL

#include "values/withdrawal_info.h"
#include "api/atm_resource_info_service.h"
#include "api/atm_withdrawal_calculation_service.h"
#include "withdrawal_info_impl.h"

#include <map>
#include <set>
#include <algorithm>

/**
 * @author hasherezade
 *
 */

class PropSol
{
public:
	PropSol() : pieces(0) { }

	std::vector<DenominationBundle> solVec;
	long getPieces() { return pieces; }

	void append(DenominationBundle got);

	unsigned long long totalValue();

protected:

	long pieces;
};
//--------------------------------------------------------------------------------

class AtmWithdrawalCalculationServiceImpl:
    public AtmWithdrawalCalculationService
{
public:
    AtmWithdrawalCalculationServiceImpl()
		: m_atmResourceInfoService(NULL) {}

	void setAtmResourceInfoService(AtmResourceInfoService *service);
	
	WithdrawalInfo *calculateWithdrawal(const Money &requestedAmount);

private:
	PropSol* findMinPossible(unsigned long long demandedVal, std::vector<DenominationBundle> &vec);

	PropSol *calculateProposal(unsigned long long money, 
		std::vector<DenominationBundle> &vec,
		std::vector<DenominationBundle>::iterator from, 
		std::vector<DenominationBundle>::iterator to);

	void resetHelpers();

	/* helpers */
	std::map<unsigned long long, PropSol*> minPossibleSols;

	/* ATM resources */ 
	AtmResourceInfoService *m_atmResourceInfoService;
};

#endif // ATM_WITHDRAWAL_CALCULATION_SERVICE_IMPL

