#include "LinuxDaemonInstaller.h"

#include <iostream>

LinuxDaemonInstaller::LinuxDaemonInstaller()
{
}

LinuxDaemonInstaller::~LinuxDaemonInstaller()
{
}

void LinuxDaemonInstaller::install(Daemon *component)
{
    std::cout << "Installing daemon binary on linux host" << std::endl;
}
