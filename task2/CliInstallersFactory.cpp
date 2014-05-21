#include "CliInstallersFactory.h"

#include "LinuxCliInstaller.h"
#include "WinXpCliInstaller.h"
#include "Win7CliInstaller.h"
#include "MacOsCliInstaller.h"


CliInstallersFactory::~CliInstallersFactory()
{ 
	deleteSupported();
}

CliInstallersFactory::CliInstallersFactory()
{
	supportOS(LINUX, new LinuxCliInstallerBuilder());
	supportOS(WIN_XP, new WinXpCliInstallerBuilder());
	supportOS(WIN_7, new WinXpCliInstallerBuilder());
	supportOS(MACOS, new MacOsCliInstallerBuilder());
}