#ifndef BANKNOTE_BUNDLE_H
#define BANKNOTE_BUNDLE_H

#include <vector>

#include "denomination_bundle.h"

/**
 * Represents a bundle of banknotes. Contains only one property - 
 * an array of denomination bundles.
 */
class BanknoteBundle
{
public:

    BanknoteBundle(const std::vector<DenominationBundle> &dm)
    { m_denominationBundle = dm; }

    std::vector<DenominationBundle>& getDenominationBundle()
    { return m_denominationBundle; }
	
	long countPieces() {
		long pieces = 0;
		std::vector<DenominationBundle>::iterator itr;
		for (itr = m_denominationBundle.begin(); itr !=  m_denominationBundle.end() ;itr++) {
			pieces += itr->getAmount();
		}
		return pieces;
	}

	unsigned long long getTotalVal() {
		unsigned long long total = 0;
		std::vector<DenominationBundle>::iterator itr;
		for (itr = m_denominationBundle.begin(); itr !=  m_denominationBundle.end() ;itr++) {
			total += (itr->getAmount() * itr->getDenomination());
		}
		return total;
	}
private:
	BanknoteBundle() {}
    std::vector<DenominationBundle> m_denominationBundle;

};

#endif // BANKNOTE_BUNDLE_H

