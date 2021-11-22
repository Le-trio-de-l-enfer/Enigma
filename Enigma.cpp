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
            int x = std::rand()/((RAND_MAX)/keyLength);
            _key.push_back(x);
        }
    }

    std::string Enigma::getKeyToString() {
        std::string ret = "";
        int keyLength = 26;
        for(int i = 0; i < keyLength; i++) {
            ret += std::to_string(_key.at(i)) + " ";
        }
        
        return ret;
    }


    void Enigma::encode(){};
    void Enigma::decode(){};

}