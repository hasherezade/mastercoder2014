#ifndef CLIINSTALLERFACTORY_H_
#define CLIINSTALLERFACTORY_H_

#include "CliInstaller.h"

class CliInstallersFactory : public ComponentInstallersFactory
{
public:
	virtual ~CliInstallersFactory();
	CliInstallersFactory();
};

#endif /* CLIINSTALLERFACTORY_H_ */
