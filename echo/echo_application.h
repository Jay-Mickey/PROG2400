//
// Created by McJay on 2024-01-08.
//

#ifndef PROG2400_ECHO_APPLICATION_H
#define PROG2400_ECHO_APPLICATION_H

#include <iostream>

class EchoApplication {
    static constexpr std::string END_VALUE = "end";
    std::istream& _cin;
    std::ostream& _cout;
    std::string _input;
public:
    explicit EchoApplication(std::istream& in, std::ostream& out);
    void input();
    void output();
    void run();
};


#endif //PROG2400_ECHO_APPLICATION_H
