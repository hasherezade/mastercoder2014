#ifndef WIN7DAEMONINSTALLER_H_
#define WIN7DAEMONINSTALLER_H_

#include <string>

#include "DaemonInstaller.h"

class Win7DaemonInstaller : public DaemonInstaller
{
public:
    Win7DaemonInstaller();
    virtual ~Win7DaemonInstaller();

    void install(Daemon *component);

};

class Win7DaemonInstallerBuilder : public ComponentInstallerBuilder
{
public:
	virtual ComponentInstaller* build() { return new Win7DaemonInstaller(); }
};
#endif /* WIN7DAEMONINSTALLER_H_ */
