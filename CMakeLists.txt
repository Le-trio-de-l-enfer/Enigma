cmake_minimum_required(VERSION 3.20)
project(Enigma)

set(CMAKE_CXX_STANDARD 14)

add_executable(Enigma main.cpp Encrypt.cpp Encrypt.h Enigma.cpp Enigma.h Enigma2Rotors.cpp Enigma2Rotors.h)
