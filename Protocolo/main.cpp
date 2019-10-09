#include <iostream>
#include <fstream>
#include <string>
#include "CifradoSimetrico.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    CifradoSimetrico ra;
    ra.cifrado("hola como estas");

    string r1Rojo;
    string claveEnigma;
    int filas;
    int columnas;
    string claveVigenere;
    int a;
    int b;
    string mensaje;
    string copia;
    int i=0;
    ifstream entrada ("textoCifrado.txt");
    ofstream salida ("textoDesifrado.txt");
    while (getline(entrada,copia)) {
            //cout<<copia<<endl;
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
    cout<<endl;
    cout<<des<<endl;

    return 0;
}
