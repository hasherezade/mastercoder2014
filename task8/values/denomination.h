/*
 * Reprezentuje informacjê o wielkosci nominalu
 */
#ifndef DENOMINATION_H
#define DENOMINATION_H

class Denomination
{
public:

    Denomination(unsigned long long value)
    { 
		m_value = value;
	}

    unsigned long long getDenomination() const
    { 
		return m_value;
	}

	bool operator<(Denomination other) const
    {
		return this->m_value < other.m_value;
    }
		
	bool operator>(Denomination other) const
    {
		return this->m_value > other.m_value;
    }

	bool operator==(Denomination other) const
    {
		return this->m_value == other.m_value;
    }

	operator unsigned long long()
    {
		return m_value;
    }

private:

    Denomination() {}

    unsigned long long m_value;
};

#endif // DENOMINATION_H

