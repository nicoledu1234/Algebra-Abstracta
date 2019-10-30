#ifndef ENIGMA_H
#define ENIGMA_H
#include <fstream>

using namespace std;

class Enigma
{
    public:
        string r1Azul="abcdefghijklmnopqrstuvwxyz0123456789 ";
        string r1Rojo;
        string r2Azul="abcdefghijklmnopqrstuvwxyz0123456789 ";
        string r2Rojo;
        string r3Azul="abcdefghijklmnopqrstuvwxyz0123456789 ";
        string r3Rojo;
        string clave;
        int alfabetoTam=r1Azul.length();
        Enigma();
        Enigma(string clave,string r1Rojo,int filas,int columnas);
        string cifrado(string mensaje);
        string descifrado(string mensaje);
        virtual ~Enigma();

    protected:

    private:
};

#endif // ENIGMA_H


