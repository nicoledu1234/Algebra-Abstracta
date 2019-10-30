#include "Afin.h"
#include "Formulas.h"
#include <iostream>
#include<vector>
#include<string>
using namespace std;

Afin::Afin()
{
 aleatorio=generadorClaves() ;
   int  d=euclides(aleatorio,tam);
    while(d!=1){
        aleatorio=generadorClaves();
        d=euclides(aleatorio,tam);
    }
    b=generadorClaves();
    while(b==aleatorio){
        b=generadorClaves();
    }
    /*
    cout<<"AFIN"<<endl;
    cout<<"a= "<<aleatorio<<" b= "<<b<<endl;
    */

}
Afin::Afin(int a, int b)
{
    int inversa=inversoMod(a,tam);
    aleatorio=inversa;
    this->b=b;
}
string Afin::cifrado(string mensaje){
    string cifrado;
    for(int i=0;i<mensaje.length();i++){
       int r=alfabeto.find(mensaje.at(i));
        //cout<<r<<"    "<<mensaje.at(i)<<endl;
        cifrado+=alfabeto.at(mod((aleatorio*r)+b,tam));
        //cout<<(mod((aleatorio*r)+b,tam))<< "   RRRR"<<endl;
        //cout<<cifrado<<endl;
    }
    return cifrado;
}

string Afin::descifrado(string mensaje){
    string descifrado;
    for(int i=0;i<mensaje.length();i++){
        int r=alfabeto.find(mensaje.at(i));
        //cout<<r<<"    "<<mensaje.at(i)<<endl;
        descifrado+=alfabeto.at(mod(aleatorio*(r-b),tam));
        //cout<<(mod(aleatorio*(r-b),tam))<<endl;
        //cout<<descifrado<<endl;
    }
    return descifrado;
}

Afin::~Afin()
{
    //dtor
}
