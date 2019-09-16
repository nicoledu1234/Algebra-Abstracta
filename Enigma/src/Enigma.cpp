#include "Enigma.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;


int mod(int t, int m) {
  int mo = -1;
  if (t < 0)
	  return (t*mo >= m) ? (t - (t/m * m)) + m : t+ m;
  return (t >= m) ? t - (t/m * m) : t;
}

Enigma::Enigma(string clave)
{
    string alf="abcdefghijklmnopqrstuvwxyz ";
    string alf1="abcdefghijklmnopqrstuvwxyz ";
    string alf2="abcdefghijklmnopqrstuvwxyz ";
    string alfabetoAleatorio;
    string alfabetoAleatorio1;
    string alfabetoAleatorio2;
    srand(time(NULL));
    int i, aleatorio,aleatorio1,aleatorio2, DESDE=0, HASTA=alf.length();
    for (i = 0; i < alf.length(); i ++){
        aleatorio = mod(rand(),(HASTA-DESDE)+DESDE);
        alf+=alf.at(aleatorio);
        alf.erase(aleatorio,1);
        alfabetoAleatorio=alf;
        aleatorio1 = mod(rand(),(HASTA-DESDE)+DESDE);
        alf1+=alf1.at(aleatorio1);
        alf1.erase(aleatorio1,1);
        alfabetoAleatorio1=alf1;
        aleatorio2 = mod(rand(),(HASTA-DESDE)+DESDE);
        alf2+=alf2.at(aleatorio2);
        alf2.erase(aleatorio2,1);
        alfabetoAleatorio2=alf2;
    }

     r1Rojo=alfabetoAleatorio;
     r2Rojo=alfabetoAleatorio1;
     r3Rojo=alfabetoAleatorio2;
     cout<<r1Rojo<<endl;
     cout<<r2Rojo<<endl;
     cout<<r3Rojo<<endl;


     r1Azul+=r1Azul.substr(0,r1Azul.find(clave.at(0)));
    r1Azul.erase(0,r1Azul.find(clave.at(0)));

    cout<<r1Azul<<endl;


    r2Azul+=r2Azul.substr(0,r2Azul.find(clave.at(1)));
    r2Azul.erase(0,r2Azul.find(clave.at(1)));

    cout<<r2Azul<<endl;

    r3Azul+=r3Azul.substr(0,r3Azul.find(clave.at(2)));
    r3Azul.erase(0,r3Azul.find(clave.at(2)));

    cout<<r3Azul<<endl;

}

Enigma::Enigma(string clave,string r1Rojo,string r2Rojo,string r3Rojo)
{
    this->r1Rojo=r1Rojo;
    this->r2Rojo=r2Rojo;
    this->r3Rojo=r3Rojo;
     r1Azul+=r1Azul.substr(0,r1Azul.find(clave.at(0)));
    r1Azul.erase(0,r1Azul.find(clave.at(0)));

    cout<<r1Azul<<endl;


    r2Azul+=r2Azul.substr(0,r2Azul.find(clave.at(1)));
    r2Azul.erase(0,r2Azul.find(clave.at(1)));

    cout<<r2Azul<<endl;

    r3Azul+=r3Azul.substr(0,r3Azul.find(clave.at(2)));
    r3Azul.erase(0,r3Azul.find(clave.at(2)));

    cout<<r3Azul<<endl;

}
string  Enigma::cifrado(string mensaje){
    string cifrado;
        for(int i=0;mensaje.length();i++){
        cifrado+=r3Rojo.at(r3Azul.find(r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i)))))));
  /*      cout<<endl;
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
        if(i<4){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
            //cout<<"1-4"<<endl;
        }
        if((i<8)&&(i>4)){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r1Azul.erase(0,1);
            //cout<<"4-8"<<endl;
        }
        if(i>8){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r2Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r2Azul.erase(0,1);
        }
        //cout<<cifrado<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<cifrado<<endl;
    return cifrado;
}

string  Enigma::descifrado(string mensaje){
    string descifrado;
        for(int i=0;mensaje.length();i++){
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
        if(i<4){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
           // cout<<"1-4"<<endl;
        }
        if((i<8)&&(i>4)){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r1Azul.erase(0,1);
            //cout<<"4-8"<<endl;
        }
        if(i>8){
            r1Azul+=r1Azul.at(0);
            r1Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r2Azul.erase(0,1);
            r2Azul+=r2Azul.at(0);
            r2Azul.erase(0,1);
        }
        cout<<descifrado<<endl;
    }
    cout<<endl;
    cout<<endl;
    cout<<descifrado<<endl;
    return descifrado;
}
Enigma::~Enigma()
{
    //dtor
}
