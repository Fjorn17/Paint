#include "application.h"

Application::Application(){
	_exit = false;
	//canvas = new Canvas();
	//toolbar = new ToolBar();
	compiler = new Compiler();
}

void Application::run() {
	do {
		string command;
		getline(cin, command);

		
		try { compiler->run(command); }
		catch (const CLI::ParseError& e) {
			std::cout << (e.get_exit_code());
			exit();
		}


		
	} while (!_exit);
}

void Application::exit() {
	_exit = true;
}