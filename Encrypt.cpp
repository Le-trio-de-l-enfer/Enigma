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
      std::ifstream fichier(this->getFichier());  //Ouverture d'un fichier en lecture

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
  void Encrypt::write(std::string nomFichier) {
      std::ofstream fichier(nomFichier);  //On essaye d'ouvrir le fichier

      if (fichier) {
          fichier << "hello world" << std::endl;
      } else {
          std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
      }
  }


  std::string Encrypt::getFichier() {
      std::cout << "Saisir le nom du fichier avec son extension (.txt) : " ;
      std::string res;
      std::cin >> res;
      return res;
  }

}
