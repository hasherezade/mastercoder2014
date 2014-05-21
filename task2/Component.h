#ifndef COMPONENT_H_
#define COMPONENT_H_

class Component
{
public:

	enum Type
	{
		CLI, 
		DEAMON, 
		CONFIGURATION, 
		REMOTE_DEAMON, 
		REMOTE_APP
	};

    virtual ~Component(){;};
	virtual Type getType() = 0;
};

#endif /* COMPONENT_H_ */
