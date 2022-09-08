#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H 

#include "shape.h"

using namespace std;


class shapeFactory {
public:
    virtual ~shapeFactory() {};
    virtual Shape* CrearShape(Color* foreColor, Color* backgroundColor, Point PointInicio, Point PointFinal, string shapeID) = 0;
};

class RectanguloFactory : public shapeFactory {
public:
    RectanguloFactory(){}
    Shape* CrearShape(Color foreColor, Color backgroundColor, Point PointInicio, Point PointFinal, string shapeID){
        return new Rectangulo(foreColor, backgroundColor, PointInicio, PointFinal, shapeID);
    }
};

class TrianguloFactory : public shapeFactory {
public:
    TrianguloFactory() {}
    Shape* CrearShape(Color foreColor, Color backgroundColor, Point PointInicio, Point PointFinal, string shapeID) {
        return new Triangulo(foreColor, backgroundColor, PointInicio, PointFinal, shapeID);
    }
};

class CirculoFactory : public shapeFactory {
public:
    CirculoFactory() {}
    Shape* CrearShape(Color foreColor, Color backgroundColor, Point PointInicio, Point PointFinal, string shapeID) {
        return new Circulo(foreColor, backgroundColor, PointInicio, PointFinal, shapeID);
    }
};



#endif // !SHAPE_FACTORY_H