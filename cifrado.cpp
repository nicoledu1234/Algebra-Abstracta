#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
class Vigenere{
    private:
        string clave;
    public:
        string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789 ";
        int tam;
        Vigenere(int tam){
            this->tam=tam;
            srand(time(NULL));
            int i, aleatorio, DESDE=0, HASTA=alfabeto.length();
            for (i = 0; i < tam; i ++){
                aleatorio = rand()%(HASTA-DESDE+1)+DESDE;
                clave+=(alfabeto.at(aleatorio));
            }
            cout<< "clave "<<clave<<endl;
        }
        Vigenere(string clave){
            this->tam=clave.length();
            this->clave=clave;
        }
        string cifrado(string mensaje){
            this->clave=clave;
            for (int i=0 ; i< tam;i++){
                int m=alfabeto.find(mensaje.at(i));
                int c=alfabeto.find(clave.at(i));
                int sumaT=(m+c)%alfabeto.length();
                mensaje.at(i)=alfabeto.at(sumaT);
            }
            cout<<"mensaje "<<mensaje<<endl;
            return mensaje;
        }
        string descifrado(string mensaje){
            tam=mensaje.length();

            for (int i=0 ; i< tam;i++){
                int m=alfabeto.find(mensaje.at(i));
                int c=alfabeto.find(clave.at(i));
                cout<<alfabeto.length()<<endl;
                int restaT=(m-c);
                cout<<alfabeto.length()<<endl;
                if(restaT<0){
                    restaT = (alfabeto.length() + restaT)%alfabeto.length();
                }
                mensaje.at(i)=alfabeto.at(restaT);
            }
            cout<<"mensaje "<<mensaje<<endl;
            return mensaje;
        }

};
int main()
{

   /* cout<<"Ingresar las letras por teclado"<<endl;
   string mensaje;
    getline(cin,mensaje);
    Vigenere a(mensaje.length());
    a.cifrado(mensaje);
*/


     cout<<"Ingresar el texto cifrado"<<endl;
     string men;
     string k;
    getline(cin,men);
    cout<<"Ingresar la clave"<<endl;
    getline(cin,k);
    Vigenere b(k);
    b.descifrado(men);

    return 0;
}
