#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Vigenere.h"
using namespace std;

int main()
{
/*
   cout<<"Ingresar las letras por teclado"<<endl;
   string mensaje;
    getline(cin,mensaje);
    Vigenere a(mensaje.length());
    a.cifrado(mensaje);

*/

     cout<<"Ingresar el texto cifrado"<<endl;
     string men;
     string k;
    getline(cin,men);
    cout<<"Ingresar la clave"<<endl;
    getline(cin,k);
    Vigenere b(k);
    b.descifrado(men);

    return 0;
}
