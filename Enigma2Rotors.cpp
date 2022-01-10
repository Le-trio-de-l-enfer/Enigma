/**
* @author Benjamin MILHET, Nicolas BENOIT
**/

#include "Enigma2Rotors.h"

#include <random>


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

        std::shuffle(key.begin(), key.end(), std::mt19937(std::random_device()()));

        return key;

    }

    //Permet d'encoder le message
    void Enigma2Rotors::encode(){
        //On affiche les deux clefs
        std::cout << this->getKey1() << std::endl;
        std::cout << this->getKey2() << std::endl;

        //On copie les deux clefs
        std::vector<char> copyKey1 = this->getKey1();
        std::vector<char> copyKey2 = this->getKey2();

        std::string res = ""; //Message final encoder
        int nbRotate = 0; //Nombre de rotation du premier rotor


        for (int i = 0; i < this->getPlain().size(); ++i) {
            int temp =  int(this->getPlain().at(i));
            if (temp != 32) {
                temp-=65;
                char res2 = copyKey1.at(temp);
                res2-=65;
                res += copyKey2.at(res2);


                rotate(copyKey1.begin(), copyKey1.begin() + 1, copyKey1.end()); //Décalage du premier rotor
                nbRotate++; //On compte le nombre de rotation du premier rotor
                if (nbRotate%26 == 0) { //Si le premier rotor a fait un tour complet
                    rotate(copyKey2.begin(), copyKey2.begin() + 1, copyKey2.end()); //Décalage du second rotor
                }
            } else { //Si le caractère est un espace, on ne change rien
                res += char(32);
            }
        }
        _cipher = res;
        std::cout << res << std::endl; //Affichage du message encoder
        this->write(res);

    }

    //Permet de décoder le message
    void Enigma2Rotors::decode(){
        //On affiche les deux clefs
        std::cout << this->getKey1() << std::endl;
        std::cout << this->getKey2() << std::endl;

        //On copie les deux clef
        std::vector<char> copyKey1 = this->getKey1();
        std::vector<char> copyKey2 = this->getKey2();

        std::string res = ""; //Message final décoder
        int nbRotate = 0; //Nombre de rotation du premier rotor

        for (int i = 0; i < this->getCipher().size(); ++i) {
            int temp =  int(this->getCipher().at(i));
            if (temp != 32) {
                auto recup = std::find(copyKey2.begin(), copyKey2.end(), temp);
                temp = recup - copyKey2.begin();
                char res2 = char(temp + 65);
                auto recup2 = std::find(copyKey1.begin(), copyKey1.end(), res2);
                res2 = recup2 - copyKey1.begin();
                res += char(res2 + 65);
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

    //Surcharge de l'opérateur << afin de pouvoir afficher une clef
    std::ostream& operator<<(std::ostream& os, const std::vector<char>& listeKey) {
        for (int i = 0; i < listeKey.size(); ++i) {
            os << listeKey.at(i);
            os << " ";
        }
        return os;
    }

}
