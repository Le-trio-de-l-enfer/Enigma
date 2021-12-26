/**
* @author Benjamin MILHET, Nicolas BENOIT
* Fichier en-tete d'une classe fille héritant de la classe Encrypt permettant de reproduire le principe de la machine Enigma avec un deux rotors
**/

#ifndef ENIGMA_ENIGMA2ROTORS_H
#define ENIGMA_ENIGMA2ROTORS_H

#include <iostream>
#include <string>
#include <vector>
#include "Encrypt.h"

namespace enigma2rotors {

    //Enigma2Rotors hérite de la class Encrypt
    class Enigma2Rotors : public encrypt::Encrypt{

        private:
            std::vector<char> _key1; //Clef du premier rotor
            std::vector<char> _key2; //Clef du deuxième rotor

        public:
            Enigma2Rotors(); //Constructeur
            std::vector<char> createKey(std::vector<char> key); //Permet de générer les deux clefs
            std::vector<char> getKey1() { return _key1; }; //Getters permettant de récupérer la clef 1
            std::vector<char> getKey2() { return _key2; }; //Getters permettant de récupérer la clef 2
            void encode() override; //Permet d'encoder le message
            void decode() override; //Permet de décoder le message
    };

    std::ostream& operator<<(std::ostream& os, const  std::vector<char>& listeKey); //Surcharge de l'opérateur << pour afficher la clef

}

#endif //ENIGMA_ENIGMA2ROTORS_H
