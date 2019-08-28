#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789 ";
    cout<<"Ingresar las letras por teclado"<<endl;
    string mensaje;
    getline(cin,mensaje);
    int tam=mensaje.length();
    string posi[36]={"a"};///
    string clave="";
    srand(time(NULL));
   int i, aleatorio, DESDE=0, HASTA=alfabeto.length();
   for (i = 0; i < tam; i ++){
             aleatorio = rand()%(HASTA-DESDE+1)+DESDE;
             posi[i]=to_string(aleatorio);
             clave.push_back(alfabeto.at(aleatorio));
   }
    cout<< "clave "<<clave<<endl;
   for (int i=0 ; i< tam;i++){

        int m=alfabeto.find(mensaje.at(i));
        int c=alfabeto.find(clave.at(i));
        int sumaT=(m+c)%37;
        mensaje.at(i)=alfabeto.at(sumaT);
   }
   cout<<"mensaje "<<mensaje<<endl;
    return 0;
}
