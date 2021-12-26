/**
* @author Benjamin MILHET, Nicolas BENOIT
*
**/

#include "Encrypt.h"
#include <iostream>
#include <fstream>
#include <cctype>

namespace encrypt {

  //On lit le contenu d'un fichier puis on l'affiche
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

  //Fonctions virtuelles
  void Encrypt::encode(){};
  void Encrypt::decode(){};


  //Manipulation de fichier

  //Permet de lire le contenu d'un fichier
  std::string Encrypt::read(std::string nomFichier) {
      std::ifstream fichier(nomFichier);  //Ouverture d'un fichier en lecture

      std::string ligne; //Contenu ligne par ligne du fichier
      std::string res = ""; //Contenu du fichier
      if (fichier) {
          while(getline(fichier, ligne)) {
              res += ligne + " ";
          }
      } else {
          std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
      }

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

}
