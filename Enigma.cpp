#include "Enigma.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>

namespace enigma {

    Enigma::Enigma () {}


    void Enigma::createKey() {
        std::srand(std::time(nullptr));
        auto random = std::rand();
        int keyLength = 26;
        // A : 65, Z : 90

        for(int i = 65; i < 91; i++) {
            _key.push_back(char(i));
        }

        std::random_shuffle(_key.begin(), _key.end());

        

    }

    std::string Enigma::getKeyToString() {
        std::string ret = "";
        int keyLength = 26;
        for(int i = 0; i < keyLength; i++) {
            ret += _key.at(i);
            ret += " ";
        }
        
        return ret;
    }


    void Enigma::encode(){

    };
    void Enigma::decode(){};

}