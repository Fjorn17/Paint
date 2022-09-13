#ifndef COMMAND_H
#define COMMAND_H

#include "pubsub.h"

class Command : public PubSub<string> {
protected:
	string command;
public:
	virtual void execute() = 0;
};

class CommandSerializer : public Command {
	void execute(){
		publish("serializer",command);
	}
};
#endif // !"COMMAND_H"

