#include <iostream>
#include <fstream>
#include "Escitala.h"
#include <string>

using namespace std;

int main()
{
    ifstream entrada ("textoPlano.txt");
    ofstream salida ("textoCifrado.txt");
    string mensaje;
    while (getline (entrada,mensaje)) {
    }
    cout<<"Ingresar la clave, filas y columnas"<<endl;
    int filas;
    int columnas;
    cin>>filas;
    cin>>columnas;
    Escitala emisor(filas,columnas);
    string meme= emisor.cifrado(mensaje);
    salida << meme << endl;
    salida.close();
    entrada.close();


    cout<<"Ingresar la clave, filas y columnas"<<endl;
    int filas1;
    int columnas1;
    cin>>filas1;
    cin>>columnas1;
    Escitala reseptor(filas1,columnas1);
    ifstream entrada1 ("textoCifrado.txt");
    ofstream salida1 ("textoDescifrado.txt");
    string mensaje1;
    while (getline (entrada1,mensaje1)) {
    }

    string mensj=reseptor.descifrado(meme);
    salida1 << mensj<< endl;
    cout<<mensj<<endl;
    salida1.close();
    entrada1.close();


    return 0;
}
