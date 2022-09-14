#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "shape.h"
#include "compiler.h"

class ToolBar{
public:
    Shape* createShape(/*shared_ptr<Compiler::CommandParse> parse*/) {
        Shape* shape; //= new Triangulo(parse->foreColor, parse->backgroundColor,parse->initialPoint, parse->finalPoint);

        canvas->add(shape);
        return shape;
    };
    virtual Color createColor(string color) = 0;
    virtual Point createPoint(string point) = 0;
    //virtual ID createPoint(string id) = 0;
private:
    Canvas* canvas;
};


#endif //!TOOLBAR_H