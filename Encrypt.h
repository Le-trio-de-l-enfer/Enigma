/**
* @author Benjamin MILHET, Nicolas BENOIT
* Fichier en-tete d'une classe mere virtuel permettant de creer des algos d'encodage et de decodage
**/

#include <string>
#include <iostream>

#ifndef ENCRYPT_H
#define ENCRYPT_H

namespace encrypt {

  class Encrypt {

    //Declaration des variables
    protected:
       std::string _plain; //Message non chiffré
       std::string _cipher; //Message chiffré
       std::string getFichier(int type); //Demande a l'utilisateur qu'elle fichier il faut lire

    public:
      Encrypt();
      std::string getPlain() const; //lire le message dechiffrer
      std::string getCipher() const; //lire le message chiffrer
      virtual void encode(); //Permet d'encoder le message non-chiffrer
      virtual void decode(); //Permet de decoder le message chiffrer
      std::string read(); //Permet de lire le contenu d'un fichier
      void write(std::string message); //Permet d'ecrire dans un fichier


  };
}

#endif
