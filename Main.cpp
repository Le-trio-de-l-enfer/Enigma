#include <iostream>
#include "Enigma.h"
#include "Enigma2Rotors.h"

int main(int argc, char const *argv[])
{

  char res;

  do {
    std::cout << "Veuillez choisir le nombre de rotor (1 ou 2) : ";
    std::cin >> res;
    switch (res) {
      case '1': {
        enigma::Enigma e;
        e.read();
        e.encode();
        e.decode();
        }
        break;
      case '2': {
        enigma2rotors::Enigma2Rotors enigma2Rotors;
        enigma2Rotors.read();
        enigma2Rotors.encode();
        enigma2Rotors.decode();
        }
        break;
      default:
        break;
    }
  } while(res != '1' && res != '2');

    return 0;
}
