#ifndef AFIN_H
#define AFIN_H
#include <iostream>
#include<string>
using namespace std;

class Afin
{
    private:

    public:
        int b;
        int aleatorio;
        string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789 ";
        int tam=alfabeto.size();
        Afin();
        Afin(int a, int b);
        string cifrado(string mensaje);
        string descifrado(string mensaje);
        virtual ~Afin();

    protected:

    private:
};

#endif // AFIN_H
