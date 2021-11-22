#include <string>
#include <iostream>

#ifndef ENCRYPT_H
#define ENCRYPT_H

namespace encrypt {

  class Encrypt {

    //Declaration des variables
    protected:
       std::string _plain;
       std::string _cipher;

    public:
      Encrypt();
      std::string getPlain(); //lire le message dechiffrer
      std::string getCipher(); //lire le message chiffrer
      virtual void encode(); //Permet d'encoder le message non-chiffrer
      virtual void decode(); //Permet de decoder le message chiffrer
      void read(std::string nomFichier); //Permet de lire le contenu d'un fichier
      void write(std::string nomFichier); //Permet d'ecrire dans un fichier


  };
}

#endif
