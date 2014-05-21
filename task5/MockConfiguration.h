#ifndef INCLUDED_MOCKCONFIGURATION_H_
#define INCLUDED_MOCKCONFIGURATION_H_

#include "AbstractConfiguration.h"

class MockConfiguration : public AbstractConfiguration
{
public:
    MockConfiguration() : currentType(JARO_WINKLER) {;}
    virtual ~MockConfiguration() {;}

    virtual DistanceType getDistnanceType();

    void useJaroWinkler();
    void useLevenshtein();
	
private:
    DistanceType currentType;
};


#endif // INCLUDED_MOCKCONFIGURATION_H_
