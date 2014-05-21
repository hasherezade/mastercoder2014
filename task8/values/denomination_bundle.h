/*
 * Reprezentuje informacje o ilosci banknotow w danym nominale
 */
#ifndef DENOMINATION_BUNDLE_H
#define DENOMINATION_BUNDLE_H

#include "denomination.h"

#include <string>       // std::string
#include <sstream>      // std::stringstream

class DenominationBundle
{
public:

    DenominationBundle(const Denomination &denomination, int amount)
		: m_denomination(denomination.getDenomination())
    { 
		m_amount = amount;
	}

    Denomination& getDenomination()
    { return m_denomination; }

    const Denomination& getDenomination() const
    { 
		return m_denomination;
	}

    int getAmount()
    { return m_amount; }

    int getAmount() const
    { 
		return m_amount;
	}

	unsigned long long bundleVal() {
		return m_amount * m_denomination.getDenomination();
	}

	bool operator<(DenominationBundle& other) const
    {
		return this->getDenomination() < other.getDenomination();
    }

	bool operator<(const DenominationBundle& other) const
    {
		return this->getDenomination() < other.getDenomination();
    }
	
	bool operator>(DenominationBundle& other) const
    {
		return this->getDenomination() > other.getDenomination();
    }

	bool operator==(DenominationBundle other) const
    {
		return this->getDenomination() == other.getDenomination();
    }
//---------------------------------------------------------------------
	bool operator==(unsigned long long val) const
    {
		return this->getDenomination() == val;
    }

	friend bool operator<(DenominationBundle a, unsigned long long val)
    {
        return a.m_denomination.getDenomination() < val;
    }

	friend bool operator<(unsigned long long val,DenominationBundle a)
    {
        return a.m_denomination.getDenomination() > val;
    }

private:

    DenominationBundle()
		: m_denomination(0ULL) {}

    Denomination m_denomination;
    int m_amount;
};

#endif // DENOMINATION_BUNDLE_H

