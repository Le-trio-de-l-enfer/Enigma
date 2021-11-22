#include <iostream>
#include "Enigma.h"

int main(int argc, char const *argv[])
{
    enigma::Enigma e;
    e.createKey();
    e.read("test.txt");
    std::cout << "hello world" << std::endl;

    return 0;
}
