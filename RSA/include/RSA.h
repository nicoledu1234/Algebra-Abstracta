#ifndef RSA_H
#define RSA_H
#include <vector>
#include <cstdlib>
#include <string>
#include <math.h>
#include <cstring>
#include <stdlib.h>


using namespace std;

class RSA
{
    public:
        string alfabeto = "abcdefghijklmnopqrstuvwxyz0123456789 ";
        int tamAlfabeto = alfabeto.length();
        RSA();
        vector<unsigned long long> cifrado(string mensaje,unsigned long long clavePublicaER,unsigned long long clavePublicaNR);
        string descifrado(vector<unsigned long long> mensaje,unsigned long long clavePrivadaDR,unsigned long long clavePrivadaNR);
        virtual ~RSA();

    protected:

    private:
};

#endif // RSA_H
