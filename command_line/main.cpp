#include <iostream>

void parse_command_line(auto _argc, auto _argv) {
    std::cout << "--ARGUMENTS--" << std::endl;
    for (int i = 1; i < _argc; i++) {
        std::cout << i << ". " << _argv[i] << std::endl;
    }
}

int main(int _argc, char** _argv) {               // int main(int argc, char* argv[])

    parse_command_line(_argc, _argv);

    return 0;
}