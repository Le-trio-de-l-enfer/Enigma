#include <iostream>
#include "Enigma.h"

int main(int argc, char const *argv[])
{
    enigma::Enigma e;
    e.createKey();
    e.read("../test.txt");
    //e.read("test.txt");
    e.encode();


    return 0;
}
