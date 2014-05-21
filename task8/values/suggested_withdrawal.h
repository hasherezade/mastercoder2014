#ifndef SUGGESTED_WITHDRAWAL
#define SUGGESTED_WITHDRAWAL

#include "money.h"

class SuggestedWithdrawal
{
public:

    SuggestedWithdrawal(const Money &sm, const Money &bm)
    : m_smallerAmmount(sm.getAmount())
    , m_biggerAmmount(bm.getAmount())
    {}

    const Money& getSmallerAmount() const
    { return m_smallerAmmount; }
    
    const Money& getBiggerAmount() const
    { return m_biggerAmmount; }

private:

    SuggestedWithdrawal()
    : m_smallerAmmount(0ULL)
    , m_biggerAmmount(0ULL)
    {}

    Money m_smallerAmmount;
    Money m_biggerAmmount;
};

#endif // SUGGESTED_WITHDRAWAL
 
