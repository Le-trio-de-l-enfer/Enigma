#ifndef DEF_ENIGMA
#define DEF_ENIGMA

#include <iostream>
#include <string>
#include <vector>

#include "Encrypt.h"

namespace enigma {

    class Enigma : public encrypt::Encrypt {
        // Enigma herite de la class Encrypt
        private:
            std::vector<char> _key;
            
        public:
            Enigma();
            void createKey();
            std::vector<char> getKey() { return _key; };
            void encode() override;
            void decode() override;
        
    };

    std::ostream& operator<<(std::ostream& os, const  std::vector<char>& listeKey);



}


#endif