#include "LinuxCliInstaller.h"

#include <iostream>

LinuxCliInstaller::LinuxCliInstaller()
{
}

LinuxCliInstaller::~LinuxCliInstaller()
{
}

void LinuxCliInstaller::install(CLI *cli)
{
    CliBinary *binary = cli->getBinary(LINUX);
    //do the installation
    std::cout << "Installing cli binary on linux host" << std::endl;
}
