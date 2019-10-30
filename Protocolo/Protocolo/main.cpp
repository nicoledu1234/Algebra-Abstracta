#include <iostream>
#include <fstream>
#include <string>
#include "CifradoSimetrico.h"
#include "Enigma.h"
#include "Afin.h"
using namespace std;

int main()
{

    CifradoSimetrico ra;
    ra.cifrado("cifrado con el protocolo que funciona para todos al fin");

/*
   Enigma a("ur4","29jdcegb1tqlm8 pkv7rsya5xfoh0n4u6i3zw",2,19);
    cout<<a.cifrado("uvc7rowkjia42ma2yekp1iio2lel4wta2vq001oyqu4i")<<endl;
    */

/*    Afin a(5,19,8);
    cout<<a.cifrado("0hzi9t3uc1t2bumxg1ff9ik2sw9 m9ff9md2skkmo660")<<endl;
    */


    string r1Rojo;
    string claveEnigma;
    int filas;
    int columnas;
    string claveVigenere;
    int a;
    int b;
    string mensaje;
    int i=0;
    ifstream entrada("claves.txt");
    ofstream salida ("textoDesifrado.txt");
    string copia;
    while (getline(entrada,copia)){
           /* cout<<i<<endl;
            cout<<copia<<endl;*/
            if (i==0){
                r1Rojo=copia;
            }
            if (i==1){
                claveEnigma=copia;
            }
            if (i==2){
                filas=stoi(copia);
            }
            if (i==3){
                columnas=stoi(copia);
            }
            if (i==4){
                claveVigenere=copia;
            }
            if (i==5){
                a=stoi(copia);
            }
            if (i==6){
                b=stoi(copia);
            }
            if (i==7){
                mensaje=copia;
            }
            i++;
    }

    cout<<"r1Rojo  "<<r1Rojo<<endl;
    cout<<"claveEnigma  "<<claveEnigma<<endl;
    cout<<"filas  "<<filas<<endl;
    cout<<"columnas  "<<columnas<<endl;
    cout<<"claveVigenere  "<<claveVigenere<<endl;
    cout<<"a  "<<a<<endl;
    cout<<"b  "<<b<<endl;
    cout<<"mensaje  "<<mensaje<<endl;
    CifradoSimetrico rb;
    string des=rb.descifrado(mensaje,r1Rojo,claveEnigma,filas,columnas,claveVigenere,a,b);
    cout<<"descifrado: "<<des<<endl;
    cout<<endl;
    salida<<des<<endl;

    return 0;
}
