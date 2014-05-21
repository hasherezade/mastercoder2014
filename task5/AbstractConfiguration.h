#ifndef INCLUDED_ABSTRACTCONFIGURATION_H_
#define INCLUDED_ABSTRACTCONFIGURATION_H_

#include "DistanceType.h"

class AbstractConfiguration
{
public:
    virtual DistanceType getDistnanceType() = 0;

    virtual ~AbstractConfiguration() {;}
};

#endif // INCLUDED_ABSTRACTCONFIGURATIONSERVICE_H_