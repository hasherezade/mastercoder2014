
#ifndef ATM_WITHDRAWAL_CALCULATION_SERVICE
#define ATM_WITHDRAWAL_CALCULATION_SERVICE
#include "../values/money.h"
#include "../values/withdrawal_info.h"

/**
 * Defines an API for a service that is responsible for telling ATM if
 * withdrawal of specified amount of money is possible and what banknotes
 * should be used for it.
 * 
 * @author Kupakasi Bank
 *
 */
class AtmWithdrawalCalculationService
{
public:

    AtmWithdrawalCalculationService() {}
    virtual ~AtmWithdrawalCalculationService() {}

	/**
	 * Calculates if withdrawal of a selected amount is possible.
	 * In case, it is, the method returns withdrawal info that returns
	 * possible property to true and withdrawalBundle contains
	 * information about banknotes used to withdraw. suggestedWithdrawal
	 * property contains the amount of money given as requestedAmount.
	 * If withdrawal is impossible, then possible property is set to false.
	 * Then, suggested amount returns amounts of money that are possible to 
   * withdraw and are as close to requested amount as possible. Also, one of
   * the suggested amount, should be smaller than requested one, an one should 
   * be bigger.
   * withdrawalBundle property, should contain a bundle of banknotes, that
   * should be  used to withdraw a bigger amount of money.
	 * 
	 * @param requestedAmount a requested amount of money
	 * @return information if withdrawal is possible, in which banknotes
	 * 		and if not, what are suggested amounts of money to withdraw.
	 */
	virtual WithdrawalInfo *calculateWithdrawal(const Money &requestedAmount) = 0;

};

#endif // ATM_WITHDRAWAL_CALCULATION_SERVICE

