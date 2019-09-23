#include <iostream>
#include <ctime>
#include <bitset>
#include <cstdlib>
#include <string>
#include <math.h>
#include <fstream>
#include "Vernam.h"
using namespace std;
//#define n 32


int main(){
    ifstream entrada ("textoPlano.txt");
    ofstream salida ("textoDescifrado.txt");
    string mensaje;
    while (getline (entrada,mensaje)) {
    }
    int tama=mensaje.length();
    Vernam emisor(tama);
    vector<string> mensaje1=emisor.cifrado(mensaje);
    cout<<"Ingresar la clave por teclado"<<endl;
    string k;
    cin>>k;
    Vernam receptor(k);
      cout<<receptor.descifrado(mensaje1);
    salida << receptor.descifrado(mensaje1) << endl;
    salida.close();
    entrada.close();



    return 0;
}
