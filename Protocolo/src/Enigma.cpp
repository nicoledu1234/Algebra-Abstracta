#include "Enigma.h"
#include "Escitala.h"
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;


void swapStr(string a,string b){
    string tmp=a;
    a=b;
    b=tmp;
}
int modu(int t, int m) {
  int mo = -1;
  if (t < 0)
	  return (t*mo >= m) ? (t - (t/m * m)) + m : t+ m;
  return (t >= m) ? t - (t/m * m) : t;
}

Enigma::Enigma()
{
    string alf=r1Azul;
    string alfabetoAleatorio;
    srand(time(NULL));
    int i, aleatorio, DESDE=0, HASTA=alf.length()-1;
    for (i = 0; i < alf.length(); i ++){
        aleatorio = modu(rand(),(HASTA-DESDE)+DESDE);
        //cout << "aleatorio:" << aleatorio << endl;
        alf+=alf.at(aleatorio);
       // cout << "alf: " << alf << endl;
        alf.erase(aleatorio,1);
        //cout << "Alf: "  << alf << endl;
        alfabetoAleatorio=alf;
    }
    /* cout<<"r1Azul:  "<<r1Azul<<endl;
     cout<<"r1Rojo:  "<<r1Rojo<<endl;
     cout<<endl;
*/
      r1Rojo=alfabetoAleatorio;
     /*string t=r1Rojo;
     r2Rojo=t[alfabetoTam-1];
     r2Rojo+=t;
     r2Rojo.pop_back();
     //cout<<"TAM ALLF  "<<alfabetoTam<<endl;
     Escitala generadorR2Rojo(2,(alfabetoTam+1)/2);
     r2Rojo=generadorR2Rojo.cifrado(r2Rojo);
     r2Rojo.pop_back();
     /*cout<<"r2Azul:  "<<r2Azul<<endl;
     cout<<"r2Rojo:  "<<r2Rojo<<endl;
     cout<<endl;

      string t1=r2Rojo;
     r3Rojo=t1;
     r3Rojo+=r3Rojo.substr(0,2);
     r3Rojo.erase(0,2);
     Escitala generadorR3Rojo(2,(alfabetoTam+1)/2);
     r3Rojo=generadorR3Rojo.cifrado(r3Rojo);
      r3Rojo.pop_back();
*/
}

Enigma::Enigma(string clave,string r1Rojo,int filas,int columnas)
{
    this->r1Rojo=r1Rojo;
    cout<<"r1Rojo  "<<r1Rojo<<endl;
   string t=r1Rojo;
     r2Rojo=t[alfabetoTam-1];
     r2Rojo+=t;
     r2Rojo.pop_back();
     //cout<<"TAM ALLF  "<<alfabetoTam<<endl;
     Escitala generadorR2Rojo(filas,columnas);
     r2Rojo=generadorR2Rojo.cifrado(r2Rojo);
    cout<<"r2Rojo  "<<r2Rojo<<endl;
    this->r2Rojo=r2Rojo;

    string t1=r2Rojo;
     r3Rojo=t1;
     r3Rojo+=r3Rojo.substr(0,2);
     r3Rojo.erase(0,2);
     Escitala generadorR3Rojo(filas,columnas);
     r3Rojo=generadorR3Rojo.cifrado(r3Rojo);
     this->r3Rojo=r3Rojo;
    cout<<"r3Rojo  "<<r3Rojo<<endl;

      r1Azul+=r1Azul.substr(0,r1Azul.find(clave.at(0)));
    r1Azul.erase(0,r1Azul.find(clave.at(0)));

  //  cout<<"r1Azul  "<<r1Azul<<endl;


    r2Azul+=r2Azul.substr(0,r2Azul.find(clave.at(1)));
    r2Azul.erase(0,r2Azul.find(clave.at(1)));

   // cout<<"r2Azul  "<<r2Azul<<endl;

    r3Azul+=r3Azul.substr(0,r3Azul.find(clave.at(2)));
    r3Azul.erase(0,r3Azul.find(clave.at(2)));

//   cout<<"r3Azul  "<<r3Azul<<endl;

        cout<<r1Rojo<<endl;
        cout<<r2Rojo<<endl;
        cout<<r3Rojo<<endl;

}
string  Enigma::cifrado(string mensaje){
    string cifrado;
  //  cout<<"mensaje.length()     "<<mensaje.length()<<endl;
        for(int i=0; i< mensaje.length();i++){

    //   cout<<"###########################"<<endl;
  /*      cout<<r1Rojo<<endl;
        cout<<r2Azul<<endl;
        cout<<r2Rojo<<endl;
        cout<<r3Azul<<endl;
        cout<<r3Rojo<<endl;

        cout<<r1Azul.find(mensaje.at(i))<<endl;
        cout<<r1Rojo.at(r1Azul.find(mensaje.at(i)))<<endl;
        cout<<r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i))))<<endl;
        cout<<r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i)))))<<endl;
        cout<<r3Azul.find(r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i))))))<<endl;
        cout<<r3Rojo.at(r3Azul.find(r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i)))))))<<endl;
        cout<<endl;
*/
        if((i>=4)&&(i<8)){
            r1Azul+=r1Azul[0];
            r1Azul.erase(0,1);
        //    cout<<"4-8"<<endl;
      /*        cout<<"r1Azul  "<<r1Azul<<endl;
         cout<<endl;*/
        }
        if((i<12)&&(i>=8)){
            r1Azul+=r1Azul[0];
            r1Azul.erase(0,1);
            r2Azul+=r2Azul[0];
            r2Azul.erase(0,1);
        //cout<<"9-12 "<<i<<endl;
        /*      cout<<"r1Azul "<<r1Azul<<endl;
         cout<<"r2Azul  "<<r2Azul<<endl;
         cout<<endl;
*/
        }
        if(i>=12){
            r1Azul+=r1Azul[0];
            r1Azul.erase(0,1);
            r2Azul+=r2Azul[0];
            r2Azul.erase(0,1);
            r3Azul+=r3Azul[0];
            r3Azul.erase(0,1);

            //
           // cout<<"13--"<<i<<endl;
          /*    cout<<"r1Azul  "<<r1Azul<<endl;
         cout<<"r2Azul  "<<r2Azul<<endl;
     cout<<"r2Azul  "<<r2Azul<<endl;
     */
        }
        //cout<<cifrado<<endl;
         cifrado+=r3Rojo.at(r3Azul.find(r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje[i]))))));
    }
    return cifrado;
}

string  Enigma::descifrado(string mensaje){
    string descifrado;
     cout<<"mensaje.length()     "<<mensaje.length()<<endl;
    for(int i=mensaje.length()-1;i>=0;i--){
descifrado+=r1Azul.at(r1Rojo.find(r2Azul.at(r2Rojo.find(r3Azul.at(r3Rojo.find(mensaje[i]))))));
        // cout<<"i  "<<i<<"   "<<descifrado<<endl;
        /*cout<<endl;
        cout<<r1Azul<<endl;
        cout<<r1Rojo<<endl;
        cout<<r2Azul<<endl;
        cout<<r2Rojo<<endl;
        cout<<r3Azul<<endl;
        cout<<r3Rojo<<endl;

        cout<<r1Azul.find(mensaje.at(i))<<endl;
        cout<<r1Rojo.at(r1Azul.find(mensaje.at(i)))<<endl;
        cout<<r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i))))<<endl;
        cout<<r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i)))))<<endl;
        cout<<r3Azul.find(r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i))))))<<endl;
        cout<<r3Rojo.at(r3Azul.find(r2Rojo.at(r2Azul.find(r1Rojo.at(r1Azul.find(mensaje.at(i)))))))<<endl;
        cout<<endl;
*/
         if((i>=4)&&(i<8)){
            string t1=r1Azul;
            r1Azul=r1Azul[alfabetoTam-1];
            r1Azul+=t1;
            r1Azul.pop_back();
           // cout<<"4-8"<<endl;
         /*     cout<<"r1Azul  "<<r1Azul<<endl;
         cout<<endl;*/
        }
        if((i<12)&&(i>=8)){
            string t1=r1Azul;
            r1Azul=t1[alfabetoTam-1];
            r1Azul+=t1;
            r1Azul.pop_back();
           // cout<<"r1Azul  "<<r1Azul<<endl;
            string t2=r2Azul;
            r2Azul=r2Azul[alfabetoTam-1];
            r2Azul+=t2;
            r2Azul.pop_back();
        /*    cout<<"9-12"<<endl;
            cout<<"r1Azul  "<<r1Azul<<endl;
            cout<<"r2Azul  "<<r2Azul<<endl;
         cout<<endl;
*/
        }
        if(i>=12){
              string t1=r1Azul;
            r1Azul=r1Azul[alfabetoTam-1];
            r1Azul+=t1;
            r1Azul.pop_back();
            string t2=r2Azul;
            r2Azul=r2Azul[alfabetoTam-1];
            r2Azul+=t2;
            r2Azul.pop_back();
            string t3=r3Azul;
            r3Azul=r3Azul[alfabetoTam-1];
            r3Azul+=t3;
            r3Azul.pop_back();
        // cout<<"13--"<<endl;
       /*      cout<<"r1Azul  "<<r1Azul<<endl;
         cout<<"r2Azul  "<<r2Azul<<endl;
     cout<<"r2Azul  "<<r2Azul<<endl;
*/
        }

    }
    //cout<<descifrado<<endl;

    for(int i=0;i<mensaje.size()/2;i++){

        swap(descifrado[i],descifrado[mensaje.size()-1-i]);
     //   descifrado[mensaje.size()-1-i]=tmp;
    }
    return descifrado;
}
Enigma::~Enigma()
{
    //dtor
}
