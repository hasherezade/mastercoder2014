#ifndef DAEMON_H_
#define DAEMON_H_

#include "Component.h"

class Daemon: public Component
{
	Type getType() { return Component::DEAMON; }
};

#endif /* DAEMON_H_ */
