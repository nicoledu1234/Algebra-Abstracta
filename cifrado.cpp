#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
class Vigenere{
    private:
        string clave="";
    public:
        string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789 ";
        string mensaje="";
        int tam;
        Vigenere(string mensaje){
            this->mensaje=mensaje;
            tam=mensaje.length();
        }
        Vigenere(string mensaje,string clave){
            this->mensaje=mensaje;
            tam=mensaje.length();
            this->clave=clave;
        }
        void cifrado(){
            srand(time(NULL));
            int i, aleatorio, DESDE=0, HASTA=alfabeto.length();
            for (i = 0; i < tam; i ++){
                aleatorio = rand()%(HASTA-DESDE+1)+DESDE;
                clave.push_back(alfabeto.at(aleatorio));
            }
            cout<< "clave "<<clave<<endl;
            this->clave=clave;
            for (int i=0 ; i< tam;i++){
                int m=alfabeto.find(mensaje.at(i));
                int c=alfabeto.find(clave.at(i));
                int sumaT=(m+c)%37;
                mensaje.at(i)=alfabeto.at(sumaT);
            }
            cout<<"mensaje "<<mensaje<<endl;
        }
        void descifrado(){
            tam=mensaje.length();
            for (int i=0 ; i< tam;i++){
                int m=alfabeto.find(mensaje.at(i));
                int c=alfabeto.find(clave.at(i));
                int restaT=(m-c)%37;
                if(restaT<0){
                    restaT = (37 + restaT)%37;
                }
                mensaje.at(i)=alfabeto.at(restaT);
            }
            cout<<"mensaje "<<mensaje<<endl;
        }

};
int main()
{
    cout<<"Ingresar las letras por teclado"<<endl;
    string mensaje;
    getline(cin,mensaje);
    Vigenere a(mensaje);
    a.cifrado();
    /*
    string men="at";
    string k="nf";
    Vigenere b(men,k);
    b.descifrado();
    */

    return 0;
}
