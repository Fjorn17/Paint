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
    struct CommandParse {
        string typeshape;
        vector<int> initialPoint;
        vector<int> finalPoint;
        string foreColor, backgroundColor;
        int ID;
    };

    Compiler(Application* app) :app(app) { setup(); }

    void setup() {
        auto parse = make_shared<CommandParse>();

        setupCreate(parse);
        setupExit();
    }

    void run(string command) {
        addCommand(command);
    }
    void addCommand(string command) {
        cli.parse(command);
       //pasar el string al historial
       //new command
        // commands.push(command);
    }
private:
    void setupCreate(shared_ptr<CommandParse> parse) {
        auto* sub = cli.add_subcommand("create")->immediate_callback();
        auto aux = app;
        sub->callback([parse,aux] {CommandCreateShape(aux->canvas, aux->toolbar, parse); });

        sub->add_option("-s, --shape", parse->typeshape)->required();
        sub->add_option<vector<int>>("-i, --initialPoint", parse->initialPoint)->required();
        sub->add_option<vector<int>>("-f, --finalPoint", parse->finalPoint)->required();
        sub->add_option("--foreColor", parse->foreColor);
        sub->add_option("--backgroundColor", parse->backgroundColor);
    }

    void setupExit() {
        auto* sub = cli.add_subcommand("exit")->immediate_callback();
        sub->callback([] {});
    }

    void setupList() {
        auto* sub = cli.add_subcommand("list")->immediate_callback();
        sub->callback([] {});
    }
    CLI::App cli;
    Application* app;
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


