#include <iostream>
#include "CLI/App.hpp"


int main(){
    CLI::App app{"App description"};

    std::string filename = "default";
    app.add_option("-f,--file", filename, "A help string");

    CLI11_PARSE(app, argc, argv);
    return 0;
}


