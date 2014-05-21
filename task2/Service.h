#ifndef SERVICE_H_
#define SERVICE_H_

#include <vector>

#include "Component.h"

class Service
{
public:
    Service(const std::vector<Component*> &components);
    virtual ~Service();

    std::vector<Component *> & getComponents();

private:
    std::vector<Component *> components;
};

#endif /* SERVICE_H_ */
