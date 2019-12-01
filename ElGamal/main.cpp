#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <Gamal.h>
using namespace std;
int main()
{
Gamal gm(1024);
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
        vector<string> cif=gm.cifrado(msg);
        salida<<cif[0]<<endl;
        salida<<cif[1]<<endl;
        msg.clear();
      }

      if(option==2){
        cout<<" Para descifrar"<<endl;
        vector<string> descif;
        ifstream entrada("textoCifrado.txt");
        ofstream salida ("textoDescifrado.txt");
        string copia;
        while (getline(entrada,copia)){
        msg+=copia;
        cout<<"mensaje "<<msg<<endl;
        descif.push_back(msg);
        msg.clear();
        }
        string mensDescifrado=gm.descifrado(descif);
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
