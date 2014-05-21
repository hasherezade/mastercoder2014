#include "DaemonInstaller.h"

#include <iostream>

DaemonInstaller::DaemonInstaller()
{
}

DaemonInstaller::~DaemonInstaller()
{
}

void DaemonInstaller::install(Component *component)
{
	return install(dynamic_cast<Daemon *>(component));
}
