#ifndef WITHDRAWAL_INFO_IMPL
#define WITHDRAWAL_INFO_IMPL

#include "values/withdrawal_info.h"

class WithdrawalInfoImpl : public WithdrawalInfo
{
public:
    
    WithdrawalInfoImpl(bool v_possible, BanknoteBundle* v_bundle, SuggestedWithdrawal* v_withdrawal)
		: WithdrawalInfo(), possible(v_possible), bundle(v_bundle), withdrawal(v_withdrawal) {}

    virtual ~WithdrawalInfoImpl() { delete bundle; delete withdrawal; }

	virtual bool isPossible() { return possible; }
	virtual BanknoteBundle *getWithdrawalBundle() { return bundle; }
	virtual SuggestedWithdrawal *getSuggestedWithdrawal() { return withdrawal; }

	virtual void print();

protected:
	bool possible;
	BanknoteBundle* bundle;
	SuggestedWithdrawal* withdrawal;
};

#endif // WITHDRAWAL_INFO_IMPL

