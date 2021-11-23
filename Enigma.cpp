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

        for (int i = 65; i < 91; i++) {
            _key.push_back(char(i));
        }

        std::random_shuffle(_key.begin(), _key.end());


    }


    void Enigma::encode(){
        std::cout << this->getKey() << std::endl;
        std::string res = "";

        for (int i = 0; i < this->getPlain().size(); ++i) {
            int temp =  int(this->getPlain().at(i));
            if (temp != 32) {
                temp-=65;
                res += this->getKey().at(temp);

            } else {
                res += char(32);
            }
            rotate(this->_key.begin(), this->_key.begin() + 1, this->_key.end());
        }
        std::cout << res << std::endl;

    }

    void Enigma::decode(){

    }

    std::ostream& operator<<(std::ostream& os, const std::vector<char>& listeKey) {
        for (int i = 0; i < listeKey.size(); ++i) {
            os << listeKey.at(i);
            os << " ";
        }
        return os;
    }

}