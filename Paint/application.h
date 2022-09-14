#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include "singleton.h"
#include "CLI11.hpp"
#include "compiler.h"

class Application {
	 
private:
	bool _exit;
	Compiler* compiler;
	Canvas* canvas;
	ToolBar* toolbar;
	
public:
	Application();
	//Application(Application &other) = delete;
	//void operator=(const Application&) = delete;

	void run();
	void exit();

	
};


#endif 
