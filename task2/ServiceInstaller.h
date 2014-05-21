#ifndef SERVICEINSTALLER_H_
#define SERVICEINSTALLER_H_

#include "Service.h"
#include "UserPreferences.h"
#include "ComponentInstaller.h"
#include <map>

class ServiceInstaller
{
public:

    void installService(Service service, UserPreferences userPreferences);

	bool supportComponentType(Component::Type type, ComponentInstallersFactory*);
	void deleteSupported();

protected:
	std::map<Component::Type, ComponentInstallersFactory*> supported;
};

#endif /* SERVICEINSTALLER_H_ */
