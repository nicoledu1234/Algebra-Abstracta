#include "RSA.h"
#include <iostream>
#include<string>
#include <ctime>
#include<vector>
#include <cstdlib>
#include "Formulas.h"

using namespace std;
RSA::RSA(){
    unsigned long long p;
    unsigned long long q;
    generadorClaves(p,q);
	//cout << "RSA p  " << p << endl;
	//cout << "RSA q  " << q << endl;


	unsigned long long N;
	N=p*q;

	unsigned long long phiN;
	phiN=(p-1)*(q-1);

	unsigned long long e;
	e=generadorAleatorios(phiN);
	while(euclides(phiN,e)!=1){
        e=generadorAleatorios(phiN);
	}

	unsigned long long d;
	d=inversoMod(e, phiN);

	cout<<"Clave Publica:  " << " e= "<<e<<"   N=  "<< N<<endl;
	cout<<"Clave Privada:  " << " d= "<<d<<"   N=  "<< N<<endl;


}
vector<unsigned long long> RSA::cifrado(string mensaje,unsigned long long clavePublicaER,unsigned long long clavePublicaNR){
    vector<unsigned long long> cifrado;
    cifrado.clear();
    cout<<mensaje<<endl;
    for(int i=0; i<mensaje.size();i++){
        unsigned long long temp=alfabeto.find(mensaje.at(i));
        //cout<<temp<<endl;
        unsigned long long c=mod(ExponenciacionModular(temp,clavePublicaER,clavePublicaNR),clavePublicaNR);
        cout<< c<<endl;
        cifrado.push_back(c);
        //cout<<cifrado[i]<<endl;
    }
   return cifrado;
}
string RSA::descifrado(vector<unsigned long long> mensaje,unsigned long long clavePrivadaDR,unsigned long long clavePrivadaNR){
    string descifrado;
    for(int i=0; i<mensaje.size();i++){
        unsigned long long temp=mensaje[i];
        unsigned long long c=mod(ExponenciacionModular(temp,clavePrivadaDR,clavePrivadaNR),clavePrivadaNR);
        cout<< "temp  "<< temp<<endl;
        cout<< "clavePrivadaDR "<<clavePrivadaDR<<endl;
        cout<< "clavePrivadaNR "<<clavePrivadaNR<<endl;
        cout<< c<<endl;
        descifrado+=alfabeto.at(c);
    }
    return descifrado;
}
RSA::~RSA()
{
    //dtor
}
