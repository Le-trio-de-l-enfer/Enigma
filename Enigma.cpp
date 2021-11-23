#include "Enigma.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <random>

namespace enigma {

    Enigma::Enigma () {
        this->createKey();
    }


    void Enigma::createKey() {
        std::srand(std::time(nullptr));
        //auto random = std::rand();
        //int keyLength = 26;
        // A : 65, Z : 90

        for (int i = 65; i < 91; i++) {
            _key.push_back(char(i));
        }

        std::random_shuffle(_key.begin(), _key.end());


    }


    void Enigma::encode(){
        std::cout << this->getKey() << std::endl;
        std::vector<char> copyKey = this->getKey();
        std::string res = "";

        for (int i = 0; i < this->getPlain().size(); ++i) {
            int temp =  int(this->getPlain().at(i));
            if (temp != 32) {
                temp-=65;
                res += copyKey.at(temp);
                //std::cout << temp << copyKey.at(temp) << "   " << char(temp+65) << std::endl;

                rotate(copyKey.begin(), copyKey.begin() + 1, copyKey.end());

            } else {
                res += char(32);
            }

        }
        _cipher = res;
        std::cout << res << std::endl;

    }

    void Enigma::decode(){
        std::string res = "";
        std::cout << this->getKey() << std::endl;
        std::vector<char> copyKey = this->getKey();

        for (int i = 0; i < this->getCipher().size(); ++i) {
            int temp =  int(this->getCipher().at(i));
            if (temp != 32) {
                auto recup = std::find(copyKey.begin(), copyKey.end(), temp);
                temp = recup - copyKey.begin();
                //temp -= 65;
                res += char(temp + 65);
                //std::cout << temp << copyKey.at(temp) << std::endl;
                rotate(copyKey.begin(), copyKey.begin() + 1, copyKey.end());

            } else {
                res += char(32);
            }

        }
        //_plain = res;
        std::cout << res << std::endl;
    }

    std::ostream& operator<<(std::ostream& os, const std::vector<char>& listeKey) {
        for (int i = 0; i < listeKey.size(); ++i) {
            os << listeKey.at(i);
            os << " ";
        }
        return os;
    }

}