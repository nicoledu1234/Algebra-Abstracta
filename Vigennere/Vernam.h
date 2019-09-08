#ifndef VERNAM_H
#define VERNAM_H
#include <iostream>
#include <ctime>
#include <bitset>
#include <cstdlib>
#include <string>
#include <math.h>
using namespace std;

class Vernam
{
    private:
        string clave;
        string claveNum[37];
    public:
        string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789 ";
        int tamAlfabeto=alfabeto.length();
        int tam;
        string mensajeNum[37];
        Vernam(int tam);
        Vernam(string clave);
        string cifrado(string mensaje);
        string descifrado(string mensaje);
        virtual ~Vernam();

    protected:

    private:
};

#endif // VERNAM_H
