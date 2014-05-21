#include "Service.h"

Service::Service(const std::vector<Component *> &components)
{
    this->components = components;
}

Service::~Service()
{
}

std::vector<Component *> & Service::getComponents()
{
    return this->components;
}
