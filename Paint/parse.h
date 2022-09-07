#ifndef PARSE_H
#define PARSE_H

#include <iostream>
#include "shape.h"
using namespace std;

template <typename T, typename... Args>
T* CreateNew(Args&&... args) {
    return new T(std::forward<Args>(args)...);
};

struct CommandParse {
    string command;
    string typeshape;
    int initialPoint_x, initialPoint_y;
    int finalPoint_x, finalPoint_y;
    string foreColor,backgroundColor;
    int ID;
};



/*
int main() {

    CommandParse parse = { "create","triangle"};

    auto createShape = [&]() {
        return CreateNew<Shape>(parse.a);
    };

    auto color = createShape();
    return 0;
}*/

#endif 
