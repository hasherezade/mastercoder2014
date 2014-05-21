#ifndef INCLUDED_DISTANCEVALUE_H_
#define INCLUDED_DISTANCEVALUE_H_

class DistanceValue
{

public:

    DistanceValue(double numericDistance);

    virtual ~DistanceValue() {;}

    int hashCode();

    operator double()
    {
		return m_distance;
    }

    bool operator <(const DistanceValue& dv)
    {
		return this->m_distance < dv.m_distance;
    }

    bool operator >(const DistanceValue& dv)
    {
		return this->m_distance > dv.m_distance;
    }

    bool operator ==(const DistanceValue& dv)
    {
		if (this==&dv) return true;
		if (dv.m_distance == this->m_distance) return true;

		return false;
    }

private:
    double m_distance;

};

#endif // INCLUDED_DISTANCEVALUE_H_
