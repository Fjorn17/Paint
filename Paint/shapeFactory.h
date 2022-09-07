#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H 

#include "shape.h"

using namespace std;


class shapeFactory {
public:
    virtual ~shapeFactory() {};
    virtual Shape* CrearShape() const = 0;

    string SomeOperation() const {
        // Call the factory method to create a Product object.
        Shape* shape = this->CrearShape();
        string result = "Creator: The same creator's code has just worked with " + shape->draw();
        delete shape;
        return result;
    }
};

class RectanguloFactory : public shapeFactory {
public:
    Shape* CrearShape() const override {
        return new Rectangulo();
    }
};

void ClientCode(const Creator& creator) {
    // ...
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
        << creator.SomeOperation() << std::endl;
    // ...
}

#endif // !SHAPE_FACTORY_H