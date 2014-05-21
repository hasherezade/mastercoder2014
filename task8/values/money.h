/*
 * Reprezentuje informacje o ilosci pieniedzy.
 */
#ifndef MONEY_H
#define MONEY_H

class Money
{
public:

    Money(unsigned long long amount)
    { m_amount = amount; }

    unsigned long long getAmount() const
    { return m_amount; }

	operator unsigned long long()
    {
		return m_amount;
    }
private:

    Money() {}

    unsigned long long m_amount;

};

#endif // MONEY_H

