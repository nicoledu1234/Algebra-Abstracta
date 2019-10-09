#include <iostream>
#include "RSA.h"
//#include "Formulas.h"
//#include "Vernam.h"
using namespace std;

int main()
{
   cout<<"Alice"<<endl;
   RSA Alice;
   cout<<"Bob"<<endl;
   RSA Bob;

   string mensaje="hola";

   cout<<" Si Alice envia un mensaje a bob"<<endl;
   cout<<"Ingrese la clave Publica de bob e"<<endl;
   unsigned long long e;
   cin>>e;

   cout<<"Ingrese la clave Publica de bob N"<<endl;
   unsigned long long N;
   cin>>N;

   vector<unsigned long long> mensCifrado=Alice.cifrado(mensaje,e,N);
   cout<<mensCifrado[0]<<","<<mensCifrado[1]<<","<<mensCifrado[2]<<","<<mensCifrado[3]<<endl;

   cout<<" Si Bob quiere descifrar el mensaje"<<endl;

   cout<<"Ingrese la clave Privada de bob e"<<endl;
   unsigned long long d;
   cin>>d;

   cout<<"Ingrese la clave Privada de bob N"<<endl;
   unsigned long long Nb;
   cin>>Nb;

   string mensDescifrado=Bob.descifrado(mensCifrado,d,Nb);
   cout<<mensDescifrado<<endl;


    return 0;
}
