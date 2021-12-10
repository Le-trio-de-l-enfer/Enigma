//
// Created by Benjamin Milhet on 10/12/2021.
//

#include "Enigma2Rotors.h"


namespace enigma2rotors {

    Enigma2Rotors::Enigma2Rotors () {
        this->_key1 = this->createKey(this->_key1);
        this->_key2 = this->createKey(this->_key2);
    }


    std::vector<char> Enigma2Rotors::createKey(std::vector<char> key) {
        std::srand(std::time(nullptr));

        for (int i = 65; i < 91; i++) {
            key.push_back(char(i));
        }

        std::random_shuffle(key.begin(), key.end());

        return key;

    }


    void Enigma2Rotors::encode(){
        std::cout << this->getKey1() << std::endl;
        std::cout << this->getKey2() << std::endl;
        std::vector<char> copyKey1 = this->getKey1();
        std::vector<char> copyKey2 = this->getKey2();
        std::string res = "";
        int nbRotate = 0;
        for (int i = 0; i < this->getPlain().size(); ++i) {
            int temp =  int(this->getPlain().at(i));
            if (temp != 32) {
                temp-=65;
                char res2 = copyKey1.at(temp);
                res2-=65;
                res += copyKey2.at(res2);


                rotate(copyKey1.begin(), copyKey1.begin() + 1, copyKey1.end());
                nbRotate++;
                if (nbRotate%26 == 0) {
                    rotate(copyKey2.begin(), copyKey2.begin() + 1, copyKey2.end());
                }

            } else {
                res += char(32);
            }

        }
        _cipher = res;
        std::cout << res << std::endl;

    }

    void Enigma2Rotors::decode(){
        std::string res = "";
        std::cout << this->getKey1() << std::endl;
        std::cout << this->getKey2() << std::endl;
        std::vector<char> copyKey1 = this->getKey1();
        std::vector<char> copyKey2 = this->getKey2();
        int nbRotate = 0;

        for (int i = 0; i < this->getCipher().size(); ++i) {
            int temp =  int(this->getCipher().at(i));
            if (temp != 32) {
                auto recup = std::find(copyKey2.begin(), copyKey2.end(), temp);
                temp = recup - copyKey2.begin();
                char res2 = char(temp + 65);
                auto recup2 = std::find(copyKey1.begin(), copyKey1.end(), res2);
                res2 = recup2 - copyKey1.begin();
                res += char(res2 + 65);
                //std::cout << temp << copyKey.at(temp) << std::endl;
                rotate(copyKey1.begin(), copyKey1.begin() + 1, copyKey1.end());
                nbRotate++;
                if  (nbRotate%26 == 0) {
                    rotate(copyKey2.begin(), copyKey2.begin() + 1, copyKey2.end());

                }

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