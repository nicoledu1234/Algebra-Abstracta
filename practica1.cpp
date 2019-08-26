#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
   //string alfabeto={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','0','1','2','3','4','5','6','7','8','9',' '};
    string alfabeto="abcdefghijklmnopqrstuvwxyz0123456789 ";
    cout<<"Ingresar las letras por teclado"<<endl;
    string mensaje;
    getline(cin,mensaje);
    int tam=mensaje.length();
    cout<<tam<<endl;
    string posi[36];
    srand(time(NULL));
   int i, aleatorio, DESDE=0, HASTA=alfabeto.length();
   for (i = 1; i <= tam; i ++)
   {
             aleatorio = rand()%(HASTA-DESDE+1)+DESDE;
             
             //posi.append(to_string(aleatorio));
             ///  cout<<alfabeto.at(aleatorio)<<endl;
    
             //cout<<alfabeto.find(posi)<<endl;
             cout<<posi<< "| ";
             cout << aleatorio << " "<<endl;
             posi[i]=static_cast<str>(aleatorio);
   }
   cout << endl;
cout<<posi<<endl;



    return 0;
}
