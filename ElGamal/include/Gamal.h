
#ifndef GAMAL_H
#define GAMAL_H
#include <iostream>
#include <vector>
#include <string>

#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

class Gamal
{
    public:
        string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
        Gamal(int bits);
        int bits;
        vector<ZZ> generarRaices(ZZ primo);
        ZZ generarRaiz(ZZ primo);
        vector<string> cifrado(string text);
        string descifrado(vector<string> cipherNum);
        virtual ~Gamal();

    protected:
        ZZ p;
        ZZ e1;
        ZZ d;
        ZZ e2;

    private:
};

#endif // GAMAL_H
