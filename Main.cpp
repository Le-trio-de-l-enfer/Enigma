#include "iostream"
#include "Enigma.h"

int main(int argc, char const *argv[])
{
    Enigma e;
    e.createKey();
    std::cout << e.getKey().toString() << endl;

    std::cout << "hello world" << std::endl;

    return 0;
}
