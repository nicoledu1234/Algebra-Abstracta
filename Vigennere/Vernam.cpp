#include <iostream>
#include <ctime>
#include <bitset>
#include <cstdlib>
#include <string>
#include <math.h>
#include "Vernam.h"
using namespace std;

Vernam::Vernam(int tam){
    this->tam=tam;
    srand(time(NULL));
    int i, aleatorio, DESDE=0, HASTA=alfabeto.length();
    for (i = 0; i < tam; i ++){
        aleatorio = rand()%(HASTA-DESDE+1)+DESDE;
        clave+=(alfabeto.at(aleatorio));
    }
    cout<< "clave "<<clave<<endl;
}
Vernam::Vernam(string clave){
    this->tam=clave.length();
    this->clave=clave;
}
string  Vernam::cifrado(string mensaje){
    for (int i=0 ; i< tam;i++){
        claveNum[i]=to_string(alfabeto.find(clave.at(i)));
        mensajeNum[i]=to_string(alfabeto.find(mensaje.at(i)));
    }
    string cifrado;
    for (int i=0 ; i< tam;i++){
        bitset<8> aqui(alfabeto.find(mensaje.at(i)));
        bitset<8> r(alfabeto.find(clave.at(i)));
        bitset<8> xORTemp(aqui ^= r);
        unsigned long pos =(xORTemp.to_ulong());
        while (pos>alfabeto.length()){
            //if(pos>alfabeto.length()){
            pos = pos%alfabeto.length();
            //}
        }
        cifrado+=alfabeto.at(pos);
    }
        cout<<"cifrado "<<cifrado<<endl;
            // binario
    string cifNum[tamAlfabeto];
    cout<<endl;
    for (int i=0 ; i< tam;i++){
        cifNum[i]=to_string(alfabeto.find(cifrado.at(i)));
    }
    /*
    for (int i=0 ; i< tam;i++){
        cout<< cifNum[i]<< ",";
    }
    cout<<endl;
*/
    return cifrado;
}
string  Vernam::descifrado(string mensaje ){
    string descifrado;
    for (int i=0 ; i< tam;i++){
        bitset<8> c(alfabeto.find(mensaje.at(i)));
        bitset<8> k(alfabeto.find(clave.at(i)));
        bitset<8> xORTemp(k ^= c);
        unsigned long pos =xORTemp.to_ulong();
        // bool b=0;
        while (pos>alfabeto.length()){
            //if (pos>alfabeto.length()){
            pos = pos%alfabeto.length() ;
            // }
        }
        descifrado+=alfabeto.at(pos);
    }
    cout<<descifrado<<endl;
    cout<<endl;
    cout<<"mensaje "<<mensaje<<endl;
    cout<<"clave "<<clave<<endl;
    cout<<"cifrado "<<mensaje<<endl;
    cout<<"descifrado "<<descifrado<<endl;
    return descifrado;

}
Vernam::~Vernam()
{
    //dtor
}
