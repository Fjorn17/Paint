#include "application.h"

Application::Application(){
	_exit = false;
}

void Application::run() {
	do {
		string command;
		cin >> command;

		/*
		try { compiler.run(command); }
		catch(command){};
		*/
	} while (!_exit);
}

void Application::exit() {
	_exit = true;
}