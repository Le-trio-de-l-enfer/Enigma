/**
* @author Benjamin MILHET, Nicolas BENOIT
**/

#include "Encrypt.h"
#include <iostream>
#include <fstream>
#include <cctype>

namespace encrypt {


  Encrypt::Encrypt() {}

  //Getters
  std::string Encrypt::getPlain() const {
      return _plain;
  }

  std::string Encrypt::getCipher() const {
      return _cipher;
  }

  void Encrypt::encode(){};
  void Encrypt::decode(){};

  //Manipulation de fichier

  //Permet de lire le contenu d'un fichier
  std::string Encrypt::read() {
      std::ifstream fichier(this->getFichier(1));  //Ouverture d'un fichier en lecture

      std::string ligne; //Contenu ligne par ligne du fichier
      std::string res = ""; //Contenu du fichier
      if (fichier) {
          while(getline(fichier, ligne)) {
            res += ligne + " ";
          }
      } else {
          std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
      }

      _plain = res;
      std::transform(_plain.begin(), _plain.end(),_plain.begin(), ::toupper);
      std::cout << _plain << std::endl;

      return res;
  }

  //Permet d'écrire dans un fichier de sortie
  void Encrypt::write(std::string message) {
      std::ofstream fichier(this->getFichier(2));  //On essaye d'ouvrir le fichier

      if (fichier) {
          fichier << message << std::endl;
      } else {
          std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
      }
  }


  std::string Encrypt::getFichier(int type) {
    switch (type) {
      case 1:
        std::cout << "Saisir le nom du fichier ou lire le message : " ;
        break;
      case 2:
        std::cout << "Saisir le nom du fichier de sortie du message crypte: " ;
        break;
      default:
        std::cout << "Saisir le nom du fichier : ";
        break;
    }
      std::string res;
      std::cin >> res;
      res += ".txt";
      return res;
  }

}
