#include "CifradoSimetrico.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

ofstream salida ("textoCifrado.txt");

CifradoSimetrico::CifradoSimetrico(){
    Enigma a;
    this->r1Rojo+=a.r1Rojo;
    this->r2Rojo+=a.r2Rojo;
    this->r3Rojo+=a.r3Rojo;
    claveEnigma+=a.r3Rojo.at(0);
    claveEnigma+=a.r2Rojo.at(0);
    claveEnigma+=a.r1Rojo[0];
    cout<<"Clave Enigma " <<claveEnigma<<endl;
    cout<<endl;
    salida<<a.r1Rojo<<endl;
    salida<<claveEnigma<<endl;
    salida<<2<<endl;
    salida<<alfabetoTam/2<<endl;

}

string CifradoSimetrico::cifrado(string mensaje){
    int tamMsj=mensaje.size();
    Vigenere b(tamMsj);
    salida<<b.clave<<endl;
    string cifVigenere=b.cifrado(mensaje);
    Enigma a;
    string cifEnigma=a.cifrado(cifVigenere,a.r1Rojo,a.r2Rojo,a.r3Rojo);
    Afin c;
    salida<<c.aleatorio<<endl;
    salida<<c.b<<endl;
    string cifAfin=c.cifrado(cifEnigma);
    salida<<cifAfin<<endl;
    salida.close();
    return cifAfin;
}

string CifradoSimetrico::descifrado(string mensaje,string r1Rojo,string claveEnigma,int filas,int columnas,string claveVigenere,int a,int b){
    Afin r(a,b);
    string desAfin=r.descifrado(mensaje);
    Enigma s(claveEnigma,r1Rojo,filas,columnas);
    string desEnigma=s.descifrado(desAfin);
    Vigenere t(claveVigenere);
    string desVigenere=t.descifrado(desEnigma);
    return desVigenere;
}
CifradoSimetrico::~CifradoSimetrico()
{
    //dtor
}
