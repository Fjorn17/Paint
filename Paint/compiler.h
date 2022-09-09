#ifndef PARSE_H
#define PARSE_H

#include <iostream>
#include <vector>
#include "shape.h"
#include "commands.h"
#include "CLI11.hpp"

using namespace std;
/*
template <typename T, typename... Args>
T* CreateNew(Args&&... args) {
    return new T(std::forward<Args>(args)...);
};
*/

class Compiler {
public:
    void init() {
        
    };
    void addCommand(string name,Command command,string description) {
        Compiler.add_option(name, command, description);
    };
private:
    vector<Command> commands;
    CLI::App Compiler;
};
#endif

/*
int main() {

    CommandParse parse = { "create","triangle"};

    auto createShape = [&]() {
        return CreateNew<Shape>(parse.a);
    };

    auto color = createShape();
    return 0;
}*/


