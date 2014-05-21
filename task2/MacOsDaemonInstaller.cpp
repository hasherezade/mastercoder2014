#include "MacOsDaemonInstaller.h"

#include <iostream>

MacOsDaemonInstaller::MacOsDaemonInstaller()
{
}

MacOsDaemonInstaller::~MacOsDaemonInstaller()
{
}

void MacOsDaemonInstaller::install(Daemon *component)
{
    std::cout << "Installing daemon binary on MacOS host" << std::endl;
}
