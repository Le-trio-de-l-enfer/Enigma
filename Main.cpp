#include "iostream"
#include "Enigma.h"

int main(int argc, char const *argv[])
{
    enigma::Enigma e;
    e.createKey();
    std::cout << e << std::endl;

    std::cout << "hello world" << std::endl;

    return 0;
}
