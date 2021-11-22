#include "Encrypt.h"
#include <iostream>
#include <fstream>
#include <cctype>

namespace encrypt {


  Encrypt::Encrypt() {
        _plain = read("../test.txt");
      std::transform(_plain.begin(), _plain.end(),_plain.begin(), ::toupper);
      std::cout << _plain << std::endl;
  }

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
  std::string Encrypt::read(std::string nomFichier) {
      std::ifstream fichier(nomFichier);  //Ouverture d'un fichier en lecture

      std::string ligne;
      std::string res = "";
      if (fichier) {
          while(getline(fichier, ligne)) {
          //std::cout << ligne << std::endl;
          res += ligne + " ";
      }
      } else {
          std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
      }

      return res;
  }

  void Encrypt::write(std::string nomFichier) {
      std::ofstream fichier(nomFichier);  //On essaye d'ouvrir le fichier

      if (fichier) {
        fichier << "hello world" << std::endl;
      } else {
          std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
      }
  }

}
