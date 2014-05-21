#ifndef COMPONENTINSTALLER_H_
#define COMPONENTINSTALLER_H_

#include <string>
#include <map>

#include "Component.h"
#include "OperatingSystem.h"


class ComponentInstaller;
class ComponentInstallerBuilder;
class ComponentInstallersFactory;
//---

class ComponentInstaller
{
public:
	ComponentInstaller();
    virtual ~ComponentInstaller();

    const std::string& getHostname() const;
    void setHostname(const std::string& hostname);

	virtual void install(Component *component) = 0;

protected:
    std::string hostname;
};

//---

class ComponentInstallerBuilder
{
public:
	virtual ~ComponentInstallerBuilder() {}

	virtual ComponentInstaller* build() = 0;
};

//---

class ComponentInstallersFactory
{
public:
	virtual ~ComponentInstallersFactory() {}

	ComponentInstaller *makeInstaller(OperatingSystem os);
	bool supportOS(OperatingSystem hostOsType, ComponentInstallerBuilder *builder);
	void deleteSupported();

protected:
	std::map<OperatingSystem, ComponentInstallerBuilder *> supported;
};

#endif /* COMPONENTINSTALLER_H_ */
