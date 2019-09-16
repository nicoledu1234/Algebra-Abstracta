#ifndef ENIGMA_H
#define ENIGMA_H
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class Enigma
{
    public:
        string r1Azul="abcdefghijklmnopqrstuvwxyz ";
        string r1Rojo;
        string r2Azul="abcdefghijklmnopqrstuvwxyz ";
        string r2Rojo;
        string r3Azul="abcdefghijklmnopqrstuvwxyz ";
        string r3Rojo;
        int alfabetoTam=r1Azul.length();
        Enigma(string clave);
        Enigma(string clave,string r1Rojo,string r2Rojo,string r3Rojo);
        string cifrado(string mensaje);
        string descifrado(string mensaje);
        virtual ~Enigma();

    protected:

    private:
};

#endif // ENIGMA_H
