/**
* @author Benjamin MILHET, Nicolas BENOIT
* Fichier en-tete d'une classe fille héritant de la classe Encrypt permettant de reproduire le principe de la machine Enigma avec un seul rotor
**/

#ifndef DEF_ENIGMA
#define DEF_ENIGMA

#include <iostream>
#include <string>
#include <vector>

#include "Encrypt.h"

namespace enigma {

    // Enigma herite de la class Encrypt
    class Enigma : public encrypt::Encrypt {

        private:
            std::vector<char> _key; //Clef pour encoder/décoder

        public:
            Enigma(); //Constructeur
            void createKey(); //Fonction permettant de générer une clef
            std::vector<char> getKey() { return _key; }; //Getters permettant de récupérer la clef
            void encode() override; //Permet d'encoder le message
            void decode() override; //Permet de décoder le message

    };

    std::ostream& operator<<(std::ostream& os, const  std::vector<char>& listeKey); //Surcharge de l'opérateur << pour afficher la clef



}


#endif
