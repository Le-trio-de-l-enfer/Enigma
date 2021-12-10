#include <iostream>
#include "Enigma.h"
#include "Enigma2Rotors.h"

int main(int argc, char const *argv[])
{
    enigma::Enigma e;
    e.read("../test.txt");
    //e.read("test.txt");
    e.encode();
    e.decode();

    enigma2rotors::Enigma2Rotors enigma2Rotors;
    enigma2Rotors.read("../test.txt");
    enigma2Rotors.encode();
    enigma2Rotors.decode();




    return 0;
}
