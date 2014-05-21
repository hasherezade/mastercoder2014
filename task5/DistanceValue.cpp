#include "DistanceValue.h"

DistanceValue::DistanceValue(double numericDistance)
    : m_distance(numericDistance)
{ ; }

int DistanceValue::hashCode()
{
    const int prime = 31;
    int result = 1;
    unsigned long long temp;
    temp = *(unsigned long long *)&m_distance;
    result = prime * result + (int)(temp ^ (temp>>32));
    return result;
}
