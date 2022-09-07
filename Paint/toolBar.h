#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "shape.h"


class ToolBar{
public:
    virtual Shape createShape(string shape) = 0;
    virtual Color createColor(string color) = 0;
    virtual Point createPoint(string point) = 0;
    //virtual ID createPoint(string id) = 0;
};


#endif //!TOOLBAR_H