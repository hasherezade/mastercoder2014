#ifndef DEAMONINSTALLER_H_
#define DEAMONINSTALLER_H_

#include <string>

#include "Daemon.h"
#include "ComponentInstaller.h"

class DaemonInstaller : public ComponentInstaller
{
public:
	DaemonInstaller();
    virtual ~DaemonInstaller();

	void install(Component *component);
	virtual void install(Daemon *deamon) = 0;
};

#endif /* DEAMONINSTALLER_H_ */
