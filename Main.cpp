#include <iostream>
#include "Enigma.h"

int main(int argc, char const *argv[])
{
    enigma::Enigma e;
    e.read("../test.txt");
    //e.read("test.txt");
    e.encode();
    e.decode();




    return 0;
}
