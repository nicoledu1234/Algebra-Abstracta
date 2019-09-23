#include <fstream>
#include "Vigenere.h"
using namespace std;

int main()
{

    ifstream entrada ("textoPlano.txt");
    ofstream salida ("textoCifrado.txt");
    string mensaje;
    while (getline (entrada,mensaje)) {
    }
    int tam=mensaje.length();

    Vigenere a(tam);
    string cifrado= a.cifrado(mensaje);

    salida << cifrado << endl;
    salida.close();
    entrada.close();


    cout<<"Ingresar la clave"<<endl;
    string k;
    getline(cin,k);
    Vigenere b(k);

    ifstream entrada1 ("textoCifrado.txt");
    ofstream salida1 ("textoDescifrado.txt");
    string mensaje1;
    while (getline (entrada1,mensaje1)) {
    }
    string descifrado=b.descifrado(cifrado);
    salida1 << descifrado << endl;
    cout<<descifrado<<endl;
    salida1.close();
    entrada1.close();

    return 0;
}
