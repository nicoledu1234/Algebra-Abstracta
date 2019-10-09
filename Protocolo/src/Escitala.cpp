#include "Escitala.h"
#include <string>
#include <iostream>
using namespace std;

Escitala::Escitala(int filas, int columnas){
    this-> filas=filas;
    this-> columnas=columnas;
}
string Escitala::cifrado(string mensaje){
    if((filas*columnas)>mensaje.length()){
        for(int i=mensaje.length();i<filas*columnas; i++){
            mensaje.push_back(' ');
        }
    }
    string cifrado;
    for(int i=0;i<columnas;i++){
        int t=0;
        for(int j=i;j<filas+i;j++,t=t+columnas){
            cifrado+=mensaje.at(i+t);
        }
    }
    /*cout<<endl;
    cout<<cifrado<<endl;*/
    return cifrado;
}
string Escitala::descifrado(string mensaje){
    string descifrado;
    for(int i=0;i<filas;i++){
        int t=0;
        for(int j=i;j<columnas+i;j++,t=t+filas){
            descifrado+=mensaje.at(i+t);
        }
    }
    cout<<descifrado<<endl;
    return descifrado;
}
Escitala::~Escitala()
{
    //dtor
}
