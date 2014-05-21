#include "CLI.h"

CLI::CLI(OperatingSystem osType)
{
    this->osType = osType;
}

CLI::~CLI()
{
}

CliBinary* CLI::getBinary(OperatingSystem osType)
{
    if (osType == this->osType)
    {
        return &this->binary;
    }

    return NULL;
}
