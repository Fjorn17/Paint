#ifndef CANVAS_H
#define CANVAS_H

#include <vector>
#include "shape.h"

using namespace std;

class Canvas{
protected:
    virtual void list() = 0;
    virtual void list(TypeShape typeShape) = 0;
    virtual void list(Point point) = 0;
    void clearSelection() {
        selectedShapes.clear();
    }

public:
    vector<Shape*> shapes;
    vector<Shape*> selectedShapes;

    ~Canvas() {
        for (auto shape : shapes) {
            delete shape;
        } 

        shapes.clear();
        clearSelection();
    }

    virtual void add(Shape *shape) = 0;

    virtual void list(TypeShape typeShape, Point point) = 0;

    virtual void selectShapeByPoint(Point point) = 0;
    virtual void selectAllShapes() = 0;

    virtual void unselectShapeByPoint(Point point) = 0;
    virtual void unselectAllShapes() = 0;

    virtual void removeShape() = 0;
    virtual void removeShape(ID id) = 0;
    virtual void removeShape(Point point) = 0;
    virtual void removeAllShapes() = 0;

    virtual void applyForeColorToShape(ID id, Color color) = 0;
    virtual void applyBackgroundColorToShape(ID id, Color color) = 0;
    virtual void moveShape (ID id, Point point) = 0;
}


#endif //!CANVAS_H
