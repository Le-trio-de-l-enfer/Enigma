#ifndef DEF_ENIGMA
#define DEF_ENIGMA

#include <iostream>
#include <string>
#include <vector>

#include "Encrypt.h"

class Enigma : public Encrypt {
    // Enigma herite de la class Encrypt
    private:
        std::vector<int> _key;
        
    public:
        void createKey();
        vector<int> getKey() { return _key };
        void encode() override;
        void decode() override;
    
}


#endif