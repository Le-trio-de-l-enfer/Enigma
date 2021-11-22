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
            std::vector<int> _key;
            
        public:
            void createKey();
            std::vector<int> getKey() { return _key; };
            // void encode() override;
            // void decode() override;
        
    };

    std::ostream& operator<<(std::ostream& os, const Enigma& enigma);

}


#endif