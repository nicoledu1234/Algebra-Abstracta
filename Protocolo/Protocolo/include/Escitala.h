#ifndef ESCITALA_H
#define ESCITALA_H
#include <iostream>
#include <string>
using namespace std;

class Escitala
{
    private:
        int filas;
        int columnas;
    public:
        int tam;
        Escitala(int filas, int columnas);
        string cifrado(string mensaje);
        string descifrado(string mensaje);
        virtual ~Escitala();
};

#endif // ESCITALA_H
