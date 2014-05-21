#ifndef CLI_H_
#define CLI_H_

#include "Component.h"
#include "UserPreferences.h"

class CliBinary
{
};

class CLI: public Component
{
public:
    CLI(OperatingSystem osType);
    virtual ~CLI();

    CliBinary* getBinary(OperatingSystem osType);
	Type getType() { return Component::CLI; }

private:
    OperatingSystem osType;
    CliBinary binary;
};

#endif /* CLI_H_ */
