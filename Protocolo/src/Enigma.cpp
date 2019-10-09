#include "Enigma.h"
#include "Escitala.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;


int modu(int t, int m) {
  int mo = -1;
  if (t < 0)
	  return (t*mo >= m) ? (t - (t/m * m)) + m : t+ m;
  return (t >= m) ? t - (t/m * m) : t;
}

Enigma::Enigma()
{
    string alf=r1Azul;
    string alfabetoAleatorio;
    srand(time(NULL));
    int i, aleatorio, DESDE=0, HASTA=alf.length()-1;
    for (i = 0; i < alf.length(); i ++){
        aleatorio = modu(rand(),(HASTA-DESDE)+DESDE);
        alf+=alf.at(aleatorio);
        alf.erase(aleatorio,1);
        alfabetoAleatorio=alf;
    }

     r1Rojo=alfabetoAleatorio;
     /*cout<<"r1Azul:  "<<r1Azul<<endl;
     cout<<"r1Rojo:  "<<r1Rojo<<endl;
     cout<<endl;
*/
     string t=r1Rojo;
     r2Rojo=t;
     r2Rojo+=r2Rojo.at(0);
     r2Rojo.erase(0,1);
     Escitala generadorR2Rojo(2,alf.length()/2);
     r2Rojo=generadorR2Rojo.cifrado(r2Rojo);
     /*cout<<"r2Azul:  "<<r2Azul<<endl;
     cout<<"r2Rojo:  "<<r2Rojo<<endl;
     cout<<endl;
*/
     string t1=r2Rojo;
     r3Rojo=t1;
     r3Rojo+=r3Rojo.substr(0,2);
     r3Rojo.erase(0,2);
     Escitala generadorR3Rojo(2,alf.length()/2);
     r3Rojo=generadorR2Rojo.cifrado(r3Rojo);
     /*cout<<"r3Azul:  "<<r3Azul<<endl;
     cout<<"r3Rojo:  "<<r3Rojo<<endl;
     cout<<endl;
     */
}

Enigma::Enigma(string clave,string r1Rojo,int filas,int columnas)
{
    this->r1Rojo+=r1Rojo;
    r1Rojo+=r1Rojo.substr(0,r1Rojo.find(clave.at(2)));
    r1Rojo.erase(0,r1Rojo.find(clave.at(2)));

    string t=r1Rojo;
    r2Rojo=t;
    r2Rojo+=r2Rojo.at(0);
    r2Rojo.erase(0,1);
    Escitala generadorR2Rojo(filas,columnas);
    r2Rojo=generadorR2Rojo.cifrado(r2Rojo);

    string t1=r2Rojo;
     r3Rojo=t1;
     r3Rojo+=r3Rojo.substr(0,2);
     r3Rojo.erase(0,2);
     Escitala generadorR3Rojo(filas,columnas);
     r3Rojo=generadorR2Rojo.cifrado(r3Rojo);
/*
    cout<<endl;

    cout<<"r1Azul:  "<<r1Azul<<endl;
    cout<<"r1Rojo  "<<r1Rojo<<endl;
    cout<<endl;
    cout<<"r2Azul:  "<<r2Azul<<endl;
     cout<<"r2Rojo  "<<r2Rojo<<endl;
     cout<<endl;
     cout<<"r3Azul:  "<<r3Azul<<endl;
     cout<<"r3Rojo  "<<r3Rojo<<endl;
     cout<<endl;
     */
}
string  Enigma::cifrado(string mensaje,string r1Rojo,string r2Rojo,string r3Rojo){
    this->r1Rojo+=r1Rojo;
    this->r2Rojo+=r2Rojo;
    this->r3Rojo+=r3Rojo;
    string cifrado;
        for(int i=0; i<mensaje.length();i++){
        cifrado+=r3Rojo.at(r3Azul.find(r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i)))))));
  /*      cout<<r1Azul<<endl;
        cout<<r1Rojo<<endl;
        cout<<r2Azul<<endl;
        cout<<r2Rojo<<endl;
        cout<<r3Azul<<endl;
        cout<<r3Rojo<<endl;

        cout<<r1Azul.find(mensaje.at(i))<<endl;
        cout<<r1Rojo.at(r1Azul.find(mensaje.at(i)))<<endl;
        cout<<r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i))))<<endl;
        cout<<r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i)))))<<endl;
        cout<<r3Azul.find(r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i))))))<<endl;
        cout<<r3Rojo.at(r3Azul.find(r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i)))))))<<endl;
        cout<<endl;
*/
        if((i>5)&&(i<9)){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
            //cout<<"1-4"<<endl;
        }
        if((i<13)&&(i>9)){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r1Azul.erase(0,1);
            //cout<<"4-8"<<endl;
        }
        if(i>13){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r2Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r2Azul.erase(0,1);
        }
        //cout<<cifrado<<endl;
    }
    return cifrado;
}

string  Enigma::descifrado(string mensaje){
    string descifrado;
        for(int i=0;i<mensaje.length();i++){
        descifrado+=r1Azul.at(r1Rojo.find(r2Azul.at(r2Rojo.find(r3Azul.at(r3Rojo.find(mensaje.at(i)))))));
        /*cout<<endl;
        cout<<r1Azul<<endl;
        cout<<r1Rojo<<endl;
        cout<<r2Azul<<endl;
        cout<<r2Rojo<<endl;
        cout<<r3Azul<<endl;
        cout<<r3Rojo<<endl;

        cout<<r1Azul.find(mensaje.at(i))<<endl;
        cout<<r1Rojo.at(r1Azul.find(mensaje.at(i)))<<endl;
        cout<<r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i))))<<endl;
        cout<<r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i)))))<<endl;
        cout<<r3Azul.find(r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i))))))<<endl;
        cout<<r3Rojo.at(r3Azul.find(r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i)))))))<<endl;
        cout<<endl;
*/
        if((i>5)&&(i<9)){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
           // cout<<"1-4"<<endl;
        }
        if((i<13)&&(i>9)){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r1Azul.erase(0,1);
            //cout<<"4-8"<<endl;
        }
        if(i>13){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r2Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r2Azul.erase(0,1);
        }
        //cout<<descifrado<<endl;
    }
    //cout<<descifrado<<endl;
    return descifrado;
}
Enigma::~Enigma()
{
    //dtor
}
