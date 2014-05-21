#ifndef WINXPCLIINSTALLER_H_
#define WINXPCLIINSTALLER_H_


#include "CliInstaller.h"

class WinXpCliInstaller : public CliInstaller
{
public:
    WinXpCliInstaller();
    virtual ~WinXpCliInstaller();

    void install(CLI *cli);
};

class WinXpCliInstallerBuilder : public ComponentInstallerBuilder
{
public:
	virtual ComponentInstaller* build() { return new WinXpCliInstaller(); }
};

#endif /* WINXPCLIINSTALLER_H_ */
