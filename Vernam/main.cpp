#include <iostream>
#include <ctime>
#include <bitset>
#include <cstdlib>
#include <string>
#include <math.h>

using namespace std;
//#define n 32


int main()
{
   string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789 ";
   int tamAlfabeto=alfabeto.length();

string mensaje;
        cout<<"Ingresar las letras por teclado"<<endl;

   string mensajeNum[tamAlfabeto];
   string claveNum[tamAlfabeto];
   string clave;

    getline(cin,mensaje);
        int tam=mensaje.length();
            srand(time(NULL));
            int i, aleatorio, DESDE=0, HASTA=alfabeto.length();
            for (i = 0; i < tam; i ++){
                aleatorio = rand()%(HASTA-DESDE+1)+DESDE;
                clave+=(alfabeto.at(aleatorio));
            }
            cout<< "clave "<<clave<<endl;
      for (int i=0 ; i< tam;i++){
                claveNum[i]=to_string(alfabeto.find(clave.at(i)));
                mensajeNum[i]=to_string(alfabeto.find(mensaje.at(i)));
            }
      for (int i=0 ; i< tam;i++){
               cout<< mensajeNum[i]<< ",";

            }
        cout<<endl;
        for (int i=0 ; i< tam;i++){
        cout<< claveNum[i]<< ",";
        }
        cout<<endl;
        cout<<"mensaje "<<mensaje<<endl;
        cout<<endl;
       string cifrado;
        for (int i=0 ; i< tam;i++){
                bitset<8> aqui(alfabeto.find(mensaje.at(i)));
        bitset<8> r(alfabeto.find(clave.at(i)));
       bitset<8> xORTemp(aqui ^ r);
        unsigned long pos =(xORTemp.to_ulong())%37;
        /*if(pos>alfabeto.length()){
                    pos = (alfabeto.length() -pos)%alfabeto.length();
                }*/
        cifrado+=alfabeto.at(pos);
        }
        cout<<cifrado<<endl;
            // binario
string cifNum[tamAlfabeto];
        cout<<endl;
            for (int i=0 ; i< tam;i++){
                cifNum[i]=to_string(alfabeto.find(cifrado.at(i)));
            }
             for (int i=0 ; i< tam;i++){
        cout<< cifNum[i]<< ",";
        }
        cout<<endl;

        string descifrado;
        for (int i=0 ; i< tam;i++){
        bitset<8> c(alfabeto.find(cifrado.at(i)));
        bitset<8> k(alfabeto.find(clave.at(i)));
       bitset<8> xORTemp(k ^= c);
        unsigned long pos =xORTemp.to_ulong()%alfabeto.length();
         /*if(pos>alfabeto.length()){
                    pos = pos %alfabeto.length();
                }*/
        descifrado+=alfabeto.at(pos);
        }
        cout<<descifrado<<endl;
        cout<<endl;
        cout<<"mensaje "<<mensaje<<endl;
        cout<<"clave "<<clave<<endl;
        cout<<"cifrado "<<cifrado<<endl;
        cout<<"descifrado "<<descifrado<<endl;

    return 0;
}
