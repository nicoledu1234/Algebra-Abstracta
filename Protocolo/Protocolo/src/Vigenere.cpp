#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include "Vigenere.h"
using namespace std;

int modulo(int t, int m) {
  int mo = -1;
  if (t < 0)
	  return (t*mo >= m) ? (t - (t/m * m)) + m : t+ m;
  return (t >= m) ? t - (t/m * m) : t;
}

Vigenere::Vigenere(int tam){
    this->tam=tam;
    srand(time(NULL));
    int i, aleatorio, DESDE=0, HASTA=alfabeto.length()-1;
    for (i = 0; i < tam; i ++){
        aleatorio = modulo(rand(),(HASTA-DESDE+1)+DESDE);
        clave+=(alfabeto.at(aleatorio));
    }
    //clave="phwvr6ilgebtyksihela12iprlxm2ltqydrc1pkl9uve";
    //cout<< "Clave Vigenere "<<clave<<endl;
}
Vigenere::Vigenere(string clave){
    this->tam=clave.length();
    this->clave=clave;
}
string Vigenere::cifrado(string mensaje){
    this->clave=clave;
    for (int i=0 ; i< tam;i++){
        int m=alfabeto.find(mensaje.at(i));
        int c=alfabeto.find(clave.at(i));
        int sumaT=modulo((m+c),alfabeto.length());
        mensaje.at(i)=alfabeto.at(sumaT);
    }
    //cout<<"mensaje "<<mensaje<<endl;
    return mensaje;
}
string Vigenere::descifrado(string mensaje){
    tam=mensaje.length();
    for (int i=0 ; i< tam;i++){
        int m=alfabeto.find(mensaje.at(i));
        int c=alfabeto.find(clave.at(i));
        //cout<<alfabeto.length()<<endl;
        int restaT=(m-c);
        //cout<<alfabeto.length()<<endl;
        if(restaT<0){
            restaT = modulo((alfabeto.length() + restaT),alfabeto.length());
        }
        mensaje.at(i)=alfabeto.at(restaT);
    }
    return mensaje;
    //cout<<"mensaje "<<mensaje<<endl;

}
Vigenere::~Vigenere()
{
    //dtor
}
