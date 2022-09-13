#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include "singleton.h"
#include "parse.h"
#include "CLI11.hpp"
#include "compiler.h"

class Application: public Singleton {
	 
private:
	bool _exit;
	Compiler* compiler;
	
	
public:
	Application();
	Application(Application &other) = delete;
	void operator=(const Application&) = delete;

	void run();
	void exit();

	Canvas* canvas;
	ToolBar* toolbar;
};


#endif 
