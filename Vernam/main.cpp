#include <iostream>
#include <ctime>
#include <bitset>
#include <cstdlib>
#include <string>
#include <math.h>
#include "Vernam.h"
using namespace std;
//#define n 32


int main(){
    string mensaje;
    cout<<"Ingresar las letras por teclado"<<endl;
    cin>>mensaje;
    int tama=mensaje.length();

    Vernam emisor(tama);
    emisor.cifrado(mensaje);

    /*Vernam receptor(bo6t);
    receptor.descifrado(mensaje);
    */

    return 0;
}
