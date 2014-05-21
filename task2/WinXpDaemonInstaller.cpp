#include "WinXpDaemonInstaller.h"

#include <iostream>

WinXpDaemonInstaller::WinXpDaemonInstaller()
{
}

WinXpDaemonInstaller::~WinXpDaemonInstaller()
{
}

void WinXpDaemonInstaller::install(Daemon *component)
{
    std::cout << "Installing daemon binary on WINXP host" << std::endl;
}
