#ifndef WIN7CLIINSTALLER_H_
#define WIN7CLIINSTALLER_H_

#include <string>

#include "CliInstaller.h"

class Win7CliInstaller : public CliInstaller
{
public:
    Win7CliInstaller();
    virtual ~Win7CliInstaller();

    void install(CLI *component);
};

class Win7CliInstallerBuilder : public ComponentInstallerBuilder
{
public:
	virtual ComponentInstaller* build() { return new Win7CliInstaller(); }
};

#endif /* WIN7CLIINSTALLER_H_ */
