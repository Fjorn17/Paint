#ifndef COMPILER_H
#define COMPILER_H

#include "CLI/App.hpp"

int compiler(int argc, char** argv) {
    CLI::App app{"App description"};

    std::string filename = "default";
    app.add_option("-f,--file", filename, "A help string");

    CLI11_PARSE(app, argc, argv);
    return 0;
}


#endif //!COMPILER_H