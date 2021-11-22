#include "Encrypt.h"
#include <iostream>
#include <fstream>

namespace encrypt {


  Encrypt::Encrypt() {

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
  void Encrypt::read(std::string nomFichier) {
      std::ifstream fichier(nomFichier);  //Ouverture d'un fichier en lecture

      std::string ligne;
      if (fichier) {
          while(getline(fichier, ligne)) {
          std::cout << ligne << std::endl;
      }
      } else {
          std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
      }
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
