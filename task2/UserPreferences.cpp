#include "UserPreferences.h"

UserPreferences::UserPreferences(std::string &hostname, OperatingSystem osType)
{
    this->hostOsType = osType;
    this->hostname = hostname;
}

UserPreferences::~UserPreferences()
{
}

UserPreferences UserPreferences::newPreferences(std::string &hostname,
        OperatingSystem osType)
{
    return UserPreferences(hostname, osType);
}

const std::string& UserPreferences::getHostname() const
{
    return hostname;
}

OperatingSystem UserPreferences::getHostOsType() const
{
    return hostOsType;
}
