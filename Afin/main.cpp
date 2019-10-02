#include <iostream>
#include "Afin.h"
#include <iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

int main()
{


    ifstream entrada ("textoPlano.txt");
    ofstream salida ("textoCifrado.txt");
    string mensaje;
    while (getline (entrada,mensaje)) {
    }
    Afin emisor;
    string tc;
    tc=emisor.cifrado(mensaje);
    cout<<tc<<endl;
    salida << tc<< endl;
    salida.close();
    entrada.close();



   cout<<"Ingresar la clave 1"<<endl;
    int clave1;
    cin>>clave1;

    cout<<"Ingresar la clave 2"<<endl;
    int clave2;
    cin>>clave2;
    cout<<endl;
    Afin receptor(clave1,clave2);

    ifstream entrada1 ("textoCifrado.txt");
    ofstream salida1 ("textoDescifrado.txt");
    string mensaje1;
    string td;
    while (getline (entrada1,mensaje1)) {
            cout<<mensaje1<<endl;
            td+=mensaje1;
    }
    cout<<td<<endl;
    string descifrado=receptor.descifrado(td);
    salida1 << descifrado<< endl;
    salida1.close();
    entrada1.close();
   cout<<td<<endl;

    return 0;
}
