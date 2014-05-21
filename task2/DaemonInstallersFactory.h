#ifndef DEAMONINSTALLERFACTORY_H_
#define DEAMONINSTALLERFACTORY_H_

#include <string>

#include "DaemonInstaller.h"

class DaemonInstallersFactory : public ComponentInstallersFactory
{
public:
	virtual ~DaemonInstallersFactory();
	DaemonInstallersFactory();
};

#endif /* DEAMONINSTALLERFACTORY_H_ */
