#ifndef WITHDRAWAL_INFO
#define WITHDRAWAL_INFO

#include "banknote_bundle.h"
#include "suggested_withdrawal.h"

/**
 * Represents information about possible withdrawal. Says if withdrawal is
 * possible as well as what banknotes should be used for withdrawal.
 * If withdrawal is not possible, then it contains suggested amount of money
 * to withdraw.
 * 
 * If 'possible' property is true, then withdrawalBundle should contain
 * information about banknotes used to withdraw money. 
 * 
 * If 'possible' property is false, then suggestedWithdrawal property must
 * contain information about the closest amount of money that is bigger and
 * less than requested amount.
 * 
 * 
 * @author Kupakasi Bank
 *
 */
class WithdrawalInfo
{
public:
    
    WithdrawalInfo() {}
    virtual ~WithdrawalInfo() {}
    

    virtual bool isPossible() = 0;
    virtual BanknoteBundle *getWithdrawalBundle() = 0;
    virtual SuggestedWithdrawal *getSuggestedWithdrawal() = 0;

	virtual void print() = 0;
};

#endif // WITHDRAWAL_INFO

