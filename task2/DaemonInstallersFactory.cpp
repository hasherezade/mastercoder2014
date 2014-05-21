#include "DaemonInstallersFactory.h"

#include "LinuxDaemonInstaller.h"
#include "WinXpDaemonInstaller.h"
#include "Win7DaemonInstaller.h"
#include "MacOsDaemonInstaller.h"

DaemonInstallersFactory::~DaemonInstallersFactory()
{
	deleteSupported();
}

DaemonInstallersFactory::DaemonInstallersFactory()
{
	supportOS(LINUX, new LinuxDaemonInstallerBuilder());
	supportOS(WIN_XP, new WinXpDaemonInstallerBuilder());
	supportOS(WIN_7, new WinXpDaemonInstallerBuilder());
	supportOS(MACOS, new MacOsDaemonInstallerBuilder());
}

