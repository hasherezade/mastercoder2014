#include "CliInstaller.h"

#include <iostream>

CliInstaller::CliInstaller()
{
}

CliInstaller::~CliInstaller()
{
}

void CliInstaller::install(Component *component)
{
	return install(dynamic_cast<CLI*>(component));
}
