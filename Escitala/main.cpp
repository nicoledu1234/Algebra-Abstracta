#include <iostream>
#include "Escitala.h"
#include <string>

using namespace std;

int main()
{
    cout<<"Ingresar las letras por teclado"<<endl;
    string mensaje;
    getline(cin,mensaje);
    cout<<"Ingresar la clave por filas y columnas"<<endl;
    int filas;
    int columnas;
    cin>>filas;
    cin>>columnas;
    Escitala emisor(filas,columnas,mensaje.length());
    string meme= emisor.cifrado(mensaje);

    Escitala reseptor(filas,columnas,mensaje.length());
    reseptor.descifrado(meme);

    return 0;
}
