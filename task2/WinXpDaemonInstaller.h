#ifndef WINXPDAEMONINSTALLER_H_
#define WINXPDAEMONINSTALLER_H_

#include <string>

#include "DaemonInstaller.h"

class WinXpDaemonInstaller : public DaemonInstaller
{
public:
    WinXpDaemonInstaller();
    virtual ~WinXpDaemonInstaller();

    void install(Daemon *component);
};

class WinXpDaemonInstallerBuilder : public ComponentInstallerBuilder
{
public:
	virtual ComponentInstaller* build() { return new WinXpDaemonInstaller(); }
};


#endif /* WINXPDAEMONINSTALLER_H_ */
