#ifndef CLIINSTALLER_H_
#define CLIINSTALLER_H_

#include <string>

#include "CLI.h"
#include "ComponentInstaller.h"

class CliInstaller : public ComponentInstaller
{
public:
	CliInstaller();
    virtual ~CliInstaller();

	virtual void install(Component *component);
	virtual void install(CLI *cli) = 0;
};

#endif /* CLIINSTALLER_H_ */
