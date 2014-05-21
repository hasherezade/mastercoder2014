#ifndef LINUXCLIINSTALLER_H_
#define LINUXCLIINSTALLER_H_

#include <string>

#include "CliInstaller.h"

class LinuxCliInstaller : public CliInstaller
{
public:
    LinuxCliInstaller();
    virtual ~LinuxCliInstaller();

    void install(CLI *cli);
};

class LinuxCliInstallerBuilder : public ComponentInstallerBuilder
{
public:
	virtual ComponentInstaller* build() { return new LinuxCliInstaller(); }
};

#endif /* LINUXCLIINSTALLER_H_ */
