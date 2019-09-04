#include <iostream>

using namespace std;

int main()
{
    cout<<"Ingresar las letras por teclado"<<endl;
   string mensaje;
    getline(cin,mensaje);
    cout<<"Ingresar la clave por filas y columnas"<<endl;
   int filas;
   int columnas;
   cin>>filas;
   cin>>columnas;
   cout<<endl;
   cout<<filas<<endl;
   cout<<columnas<<endl;
   if((filas*columnas)>mensaje.length()){
       for(int i=mensaje.length();i<filas*columnas; i++){
            mensaje.push_back(' ');
       }
   }
   string cifrado;
   for(int i=0;i<columnas;i++){
       int t=0;
     for(int j=i;j<filas+i;j++,t=t+columnas){
            cifrado+=mensaje.at(i+t);
       }
   }
   cout<<endl;
   cout<<cifrado<<endl;
   string descifrado;
    for(int i=0;i<filas;i++){
            int t=0;
     for(int j=i;j<columnas+i;j++,t=t+filas){
            descifrado+=cifrado.at(i+t);
       }
   }
   cout<<descifrado<<endl;

    return 0;
}
