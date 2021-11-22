#include "Enigma.h"

#include <cstdlib>
#include <iostream>
#include <ctime>

namespace enigma {

    Enigma::Enigma () {}


    void Enigma::createKey() {
        std::srand(std::time(nullptr));
        int random = std::rand();
        int keyLength = 26;

        for(int i = 0; i < keyLength; i++)
        {
            int x = 1 + std::rand()/((RAND_MAX)/6);
            _key.push_back(x);
        }
    }


    void Enigma::encode(){};
    void Enigma::decode(){};

}