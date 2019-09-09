#ifndef VIGENERE_H
#define VIGENERE_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Vigenere.h"
using namespace std;

class Vigenere
{
    private:
        string clave;
    public:
        string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789 ";
        int tam;
        Vigenere(int tam);
        Vigenere(string clave);
        string cifrado(string mensaje);
        string descifrado(string mensaje);
        ~Vigenere();
};

#endif // VIGENERE_H
