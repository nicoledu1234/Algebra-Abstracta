#ifndef CIFRADOSIMETRICO_H
#define CIFRADOSIMETRICO_H
#include "Enigma.h"
#include "Vigenere.h"
#include "Afin.h"
#include <fstream>

using namespace std;

class CifradoSimetrico
{
    public:
        string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789. ";
        int alfabetoTam=alfabeto.size();
        CifradoSimetrico();
        string cifrado(string mensaje);
        string descifrado(string mensaje,string r1Rojo,string claveEnigma,int filas,int columnas,string claveVigenere,int a,int b);
        virtual ~CifradoSimetrico();

    protected:

    private:
        string claveEnigma;
        string r1Rojo;
        string r2Rojo;
        string r3Rojo;
};

#endif // CIFRADOSIMETRICO_H
