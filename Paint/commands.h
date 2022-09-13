#ifndef COMMANDS_H
#define COMMANDS_H

#include "command.h"
#include "canvas.h"
#include "toolBar.h"
#include "parse.h"
#include "application.h"
#include "compiler.h"

class CommandCreateShape : public CommandSerializer{
public:
	CommandCreateShape(Canvas* canvas,ToolBar* toolbar,  shared_ptr<Compiler::CommandParse> parse) : canvas(canvas),toolbar(toolbar),shape(shape) {}
	void execute() {
		Shape* s= toolbar->createShape(parse);
		canvas->add(shape);
	}
private:
	Canvas* canvas;
	ToolBar* toolbar;
	shared_ptr<CommandParse> parse;
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

class CommandExit : public Command {
public:
	CommandList(Application* app) : canvas(canvas), shape(shape), point(point) {}
	void execute() {
		canvas->list(shape, point);
	}
private:
	Canvas* canvas;
	string shape;
	Point point;
};

/*
class CommandMove : public CommandSerializer {
public:
	CommandMove(Canvas* canvas, ToolBar* toolbar,string id, Point point) : canvas(canvas), toolbar(toolbar),id(id), point(point) {}
	void execute() {
		//Shape* s= toolbar->createShape(parse);
		canvas->moveShape(id, point);
	}
private:
	string id;
	Point point;
	Canvas* canvas;
	ToolBar* toolbar;
};

class CommandApplyForeColorToShape : public CommandSerializer {
public:
	CommandApplyForeColorToShape(Canvas* canvas, ToolBar* toolbar, string id, Color color) : canvas(canvas), toolbar(toolbar), id(id), color(color) {}
	void execute() {
		//Shape* s= toolbar->createShape(parse);
		canvas->applyForeColorToShape(id, color);
	}
private:
	string id;
	Color color;
	Canvas* canvas;
	ToolBar* toolbar;
};

class CommandApplyBackgroundColorToShape : public CommandSerializer {
public:
	CommandApplyBackgroundColorToShape(Canvas* canvas, ToolBar* toolbar, string id, Color color) : canvas(canvas), toolbar(toolbar), id(id), color(color) {}
	void execute() {
		//Shape* s= toolbar->createShape(parse);
		canvas->applyBackgroundColorToShape(id, color);
	}
private:
	string id;
	Color color;
	Canvas* canvas;
	ToolBar* toolbar;
};

class CommandSelectShapeByPoint : public CommandSerializer {
public:
	CommandSelectShapeByPoint(Canvas* canvas, ToolBar* toolbar,Point point) : canvas(canvas), toolbar(toolbar), point(point) {}
	void execute() {
		//Shape* s= toolbar->createShape(parse);
		canvas->selectShapeByPoint(point);
	}
private:
	Point point;
	Canvas* canvas;
	ToolBar* toolbar;
};

class CommandSelectAllShapes : public CommandSerializer {
public:
	CommandSelectAllShapes(Canvas* canvas, ToolBar* toolbar) : canvas(canvas), toolbar(toolbar) {}
	void execute() {
		//Shape* s= toolbar->createShape(parse);
		canvas->selectAllShapes();
	}
private:
	Canvas* canvas;
	ToolBar* toolbar;
};

class CommandUnselectShapeByPoint : public CommandSerializer {
public:
	CommandUnselectShapeByPoint(Canvas* canvas, ToolBar* toolbar, Point point) : canvas(canvas), toolbar(toolbar), point(point) {}
	void execute() {
		//Shape* s= toolbar->createShape(parse);
		canvas->unselectShapeByPoint(point);
	}
private:
	Point point;
	Canvas* canvas;
	ToolBar* toolbar;
};

class CommandUnselectAllShapes : public CommandSerializer {
public:
	CommandUnselectAllShapes(Canvas* canvas, ToolBar* toolbar) : canvas(canvas), toolbar(toolbar) {}
	void execute() {
		//Shape* s= toolbar->createShape(parse);
		canvas->unselectAllShapes();
	}
private:
	Canvas* canvas;
	ToolBar* toolbar;
};

class CommandRemoveShape : public CommandSerializer {
public:
	CommandRemoveShape(Canvas* canvas, ToolBar* toolbar, string id,Point point) : canvas(canvas), toolbar(toolbar), id(id), point(point) {}
	void execute() {
		//Shape* s= toolbar->createShape(parse);
		canvas->removeShape(id);
		canvas->removeShape(point);
	}
private:
	string id;
	Point point;
	Canvas* canvas;
	ToolBar* toolbar;
};

class CommandRemoveAllShapes : public CommandSerializer {
public:
	CommandRemoveAllShapes(Canvas* canvas, ToolBar* toolbar) : canvas(canvas), toolbar(toolbar) {}
	void execute() {
		//Shape* s= toolbar->createShape(parse);
		canvas->removeAllShapes();
	}
private:
	Canvas* canvas;
	ToolBar* toolbar;
};*/
#endif
