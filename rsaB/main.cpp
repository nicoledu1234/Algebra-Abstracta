#include <iostream>
#include <fstream>
#include "RSA.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;


int main() {
  RSA rsa(16);
  bool exit= false;
  while (!exit) {
    cout << "Que quiere hacer?"<<endl;
    cout << "1. Cifrar Mensaje" <<endl;
    cout << "2. Descifrar Mensaje" <<endl;
    cout << "3. Exit" << endl;
    int option;
    cin >> option;

    string msg;
    if(option) {
      if(option==1){
        ifstream entrada("textoPlano.txt");
        ofstream salida ("textoCifrado.txt");
        string copia;
        while (getline(entrada,copia)){
        msg+=copia;
        cout<<"mensaje "<<msg<<endl;
        }
        cout<<" Para Cifrar"<<endl;

        salida<<rsa.encrypt(msg)<<endl;
        msg.clear();
      }

      if(option==2){
        cout<<" Para descifrar"<<endl;
      /*  cout<<"Ingrese su clave Privada d"<<endl;
        ZZ d;
        cin>>d;
        cout<<"Ingrese su clave Privada  N"<<endl;
        ZZ Nb;
        cin>>Nb;
*/

        ifstream entrada("textoCifrado.txt");
        ofstream salida ("textoDescifrado.txt");
        string copia;
        while (getline(entrada,copia)){
        msg+=copia;
        cout<<"mensaje "<<msg<<endl;
        }
        string mensDescifrado=rsa.decrypt(msg);
        cout<<mensDescifrado<<endl;
        salida<<mensDescifrado<<endl;
      }
      if(option==3){
        exit = true;
      }
      else{
        continue;
      }

    }

    cout <<endl;
  }

  return 0;
}

