#ifndef LINUXDAEMONINSTALLER_H_
#define LINUXDAEMONINSTALLER_H_

#include <string>

#include "DaemonInstaller.h"

class LinuxDaemonInstaller : public DaemonInstaller
{
public:
    LinuxDaemonInstaller();
    virtual ~LinuxDaemonInstaller();

    void install(Daemon *component);
};

class LinuxDaemonInstallerBuilder : public ComponentInstallerBuilder
{
public:
	virtual ComponentInstaller* build() { return new LinuxDaemonInstaller(); }
};


#endif /* LINUXDAEMONINSTALLER_H_ */
