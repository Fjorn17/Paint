#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include "singleton.h"
#include "parse.h"

class Application: public Singleton {

private:
	bool _exit;
	Parse parse;
	void run();
public:
	Application(Application &other) = delete;
	void operator=(const Application&) = delete;

	void init();
	void exit();
};


#endif 
