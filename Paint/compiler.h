#ifndef COMPILER_H
#define COMPILER_H

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
    void run(string command) {
        addCommand(command);
    };
    void addCommand(string command) {
        cli.parse(command);
       //new command
        // commands.push(command);
    };
private:
    vector<Command> commands;
    CLI::App cli;
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


