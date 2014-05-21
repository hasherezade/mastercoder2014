#include "ComponentInstaller.h"

#include <iostream>

ComponentInstaller::ComponentInstaller()
{
}

ComponentInstaller::~ComponentInstaller()
{
}

const std::string& ComponentInstaller::getHostname() const
{
    return this->hostname;
}

void ComponentInstaller::setHostname(const std::string& hostname)
{
    this->hostname = hostname;
}

//---

ComponentInstaller* ComponentInstallersFactory::makeInstaller(OperatingSystem hostOsType)
{
	if (supported[hostOsType] == NULL) {
		return NULL;
	}
	return supported[hostOsType]->build();
}

bool ComponentInstallersFactory::supportOS(OperatingSystem hostOsType, ComponentInstallerBuilder *builder)
{
	if (supported[hostOsType] != NULL) {
		return false;
	}
	supported[hostOsType] = builder;
	return true;
}

void ComponentInstallersFactory::deleteSupported()
{
	std::map<OperatingSystem, ComponentInstallerBuilder*>::iterator itr;
	for (itr = supported.begin(); itr != supported.end(); itr++) {
		ComponentInstallerBuilder* component = itr->second;
		delete component;
	}
	supported.clear();
}