#ifndef CANVAS_H
#define CANVAS_H

#include <vector>

using namespace std;

class Canvas{
    public:
        vector<Shapes> shapeVector;
        vector<Shapes> selectShapeVector;

        virtual void createShapeCanvas(Shape shape) = 0;

        virtual void list() = 0;
        virtual void list(TypeShape typeShape) = 0;
        virtual void list(Point point) = 0;

        virtual void selectShapeByPoint(Point point) = 0;
        virtual void selectAllShapes() = 0;

        virtual void unselectShapeByPoint(Point point) = 0;
        virtual void unselectAllShapes() = 0;

        virtual void removeShape() = 0;
        virtual void removeShape(ID id) = 0;
        virtual void removeShape(Point point) = 0;
        virtual void removeAllShapes() = 0;

        virtual void applyForeColorToShape(shapeID????, Color color) = 0;
        virtual void applyBackgroundColorToShape(shapeID????, Color color) = 0;
        virtual void moveShape (shapeID????, Point point) = 0;
}


#endif //!CANVAS_H
