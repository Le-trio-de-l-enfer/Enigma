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
        int random = std::rand();
        int keyLength = 26;
        auto rng = std::default_random_engine {};
        // A : 65, Z : 90

        for(int i = 65; i < 91; i++) {
            _key.push_back(char(i));
        }

        std::shuffle(std::begin(_key), std::end(_key), rng);

        

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