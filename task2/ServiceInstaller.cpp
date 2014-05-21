#include "ServiceInstaller.h"
#include <iostream> //TODO: add logger instead

bool ServiceInstaller::supportComponentType(Component::Type type, ComponentInstallersFactory* factory)
{
	if (supported[type] != NULL) {
		return false;
	}
	supported[type] = factory;
	return true;
}

void ServiceInstaller::deleteSupported()
{
	std::map<Component::Type, ComponentInstallersFactory*>::iterator itr;
	for (itr = supported.begin(); itr != supported.end(); itr++) {
		ComponentInstallersFactory* component = itr->second;
		delete component;
	}
	supported.clear();
}

void ServiceInstaller::installService(Service service,
        UserPreferences userPreferences)
{
    std::vector<Component *> components = service.getComponents();
    for (std::vector<Component *>::iterator it = components.begin();
            it != components.end(); ++it)
    {
		Component* component = *it;
		Component::Type type = component->getType();

		if (supported[type] == NULL) {
			std::cout << "Not supported component type: " << static_cast<int>(type) << std::endl; //TODO: print to logger
			continue;
		}
		OperatingSystem hostOS = userPreferences.getHostOsType();
		ComponentInstaller* installer = this->supported[type]->makeInstaller(hostOS);

		if (installer == NULL) {
			std::cout << "Not supported OS: " << static_cast<int>(hostOS) << " for the component type: " << static_cast<int>(type) << std::endl; //TODO: print to logger
			continue;
		}

		installer->setHostname(userPreferences.getHostname());
		installer->install(*it);
		delete installer;
    }
}
