#include "Win7DaemonInstaller.h"

#include <iostream>

Win7DaemonInstaller::Win7DaemonInstaller()
{
}

Win7DaemonInstaller::~Win7DaemonInstaller()
{
}

void Win7DaemonInstaller::install(Daemon *component)
{
    std::cout << "Installing daemon binary on WIN 7 host" << std::endl;
}
