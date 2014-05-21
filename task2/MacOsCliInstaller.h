#ifndef MACOSCLIINSTALLER_H_
#define MACOSCLIINSTALLER_H_

#include <string>

#include "CliInstaller.h"

class MacOsCliInstaller : public CliInstaller
{
public:
    MacOsCliInstaller();
    virtual ~MacOsCliInstaller();

    void install(CLI *component);

private:
    std::string hostname;
};

class MacOsCliInstallerBuilder : public ComponentInstallerBuilder
{
public:
	virtual ComponentInstaller* build() { return new MacOsCliInstaller(); }
};

#endif /* MACOSCLIINSTALLER_H_ */
