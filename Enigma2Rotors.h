//
// Created by Benjamin Milhet on 10/12/2021.
//

#ifndef ENIGMA_ENIGMA2ROTORS_H
#define ENIGMA_ENIGMA2ROTORS_H

#include <iostream>
#include <string>
#include <vector>
#include "Encrypt.h"

namespace enigma2rotors {

    class Enigma2Rotors : public encrypt::Encrypt{
        // Enigma herite de la class Encrypt
        private:
            std::vector<char> _key1;
            std::vector<char> _key2;

        public:
            Enigma2Rotors();
            std::vector<char> createKey(std::vector<char> key);
            std::vector<char> getKey1() { return _key1; };
            std::vector<char> getKey2() { return _key2; };
            void encode() override;
            void decode() override;
    };

    std::ostream& operator<<(std::ostream& os, const  std::vector<char>& listeKey);

}

#endif //ENIGMA_ENIGMA2ROTORS_H
