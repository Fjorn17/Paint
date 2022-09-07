#ifndef COMMANDS_H
#define COMMANDS_H

#include "command.h"
#include "canvas.h"
#include "toolBar.h"
#include "parse.h"

class CommandCreateShape : public CommandSerializer{
public:
	CommandCreateShape(Canvas* canvas,ToolBar* toolbar) : canvas(canvas),toolbar(toolbar){}
	void execute() {
		//Shape* s= toolbar->createShape(parse);
		canvas->add(s);
	}
private:
	Canvas* canvas;
	ToolBar* toolbar;
};

class CommandList : public Command {
public:
	CommandList(Canvas* canvas,string shape,Point point) : canvas(canvas),shape(shape),point(point) {}
	void execute() {
		canvas->list(shape,point);
	}
private:
	Canvas* canvas;
	string shape;
	Point point;
};

#endif
