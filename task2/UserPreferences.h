#ifndef USERPREFERENCES_H_
#define USERPREFERENCES_H_

#include "OperatingSystem.h"
#include <string>

class UserPreferences
{
public:
    static UserPreferences newPreferences(std::string &hostname,
            OperatingSystem osType);

    virtual ~UserPreferences();

    const std::string& getHostname() const;

    OperatingSystem getHostOsType() const;

private:
    UserPreferences(std::string &hostname, OperatingSystem osType);

    OperatingSystem hostOsType;
    std::string     hostname;
};

#endif /* USERPREFERENCES_H_ */
