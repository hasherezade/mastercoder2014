#include "Component.h"
#include "ServiceInstaller.h"
#include "UserPreferences.h"
#include <vector>
#include <string>

#include "CliInstallersFactory.h"
#include "DaemonInstallersFactory.h"


int main(int argc, char **argv)
{
	/* init */
	ServiceInstaller serviceInstaller;
	serviceInstaller.supportComponentType(Component::CLI, new CliInstallersFactory());
	serviceInstaller.supportComponentType(Component::DEAMON, new DaemonInstallersFactory());

	std::vector<Component *> components;
	components.push_back(new CLI(LINUX));
	components.push_back(new Daemon());
	Service service(components);

	std::string hostname("hostname");
	UserPreferences prefs = UserPreferences::newPreferences(hostname, LINUX);

	/* install */
	serviceInstaller.installService(service, prefs);

	/* destroy */
	serviceInstaller.deleteSupported();

	std::vector<Component *>::iterator itr;
	for (itr = components.begin(); itr != components.end(); itr++) {
		delete (*itr);
	}
	return 0;
}
