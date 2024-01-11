//
// Created by McJay on 2024-01-08.
//
#include <iostream>
#include "echo_application.h"

//const std::string EchoApplication::END_VALUE = "end";

int main() {
    EchoApplication app(std::cin, std::cout);
    app.run();

    return 0;
}