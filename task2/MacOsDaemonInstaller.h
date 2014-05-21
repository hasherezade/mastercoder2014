#ifndef MACOSDAEMONINSTALLER_H_
#define MACOSDAEMONINSTALLER_H_

#include <string>

#include "DaemonInstaller.h"

class MacOsDaemonInstaller : public DaemonInstaller
{
public:
    MacOsDaemonInstaller();
    virtual ~MacOsDaemonInstaller();

    void install(Daemon *component);
};

class MacOsDaemonInstallerBuilder : public ComponentInstallerBuilder
{
public:
	virtual ComponentInstaller* build() { return new MacOsDaemonInstaller(); }
};

#endif /* MACOSDAEMONINSTALLER_H_ */
