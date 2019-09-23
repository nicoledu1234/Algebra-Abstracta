#include <iostream>
#include <ctime>
#include <bitset>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <math.h>
#include <cstring>
#include <stdlib.h>
#include "Vernam.h"
using namespace std;

int mod(int t, int m) {
  int mo = -1;
  if (t < 0)
	  return (t*mo >= m) ? (t - (t/m * m)) + m : t+ m;
  return (t >= m) ? t - (t/m * m) : t;
}

Vernam::Vernam(int tam){
    this->tam=tam;
    srand(time(NULL));
    int i, aleatorio, DESDE=0, HASTA=alfabeto.length();
    for (i = 0; i < tam; i ++){
        aleatorio = mod(rand(),(HASTA-DESDE+1)+DESDE);
        clave+=(alfabeto.at(aleatorio));
    }
    cout<< "clave "<<clave<<endl;
}
Vernam::Vernam(string clave){
    this->tam=clave.length();
    this->clave=clave;
}
vector<string> Vernam::cifrado(string mensaje){
    ofstream salida ("textoCifrado.txt");
    /*for (int i=0 ; i< tam;i++){
        claveNum[i]=to_string(alfabeto.find(clave.at(i)));
        mensajeNum[i]=to_string(alfabeto.find(mensaje.at(i)));
    }*/
    vector<string> mensajeBinario;
	vector<string> claveBinario;

	vector<string> cifradoBinario;

    string cifrado;
    int tam = mensaje.length();
    for (int i = 0; i < tam; i++) {
		int temp = alfabeto.find(mensaje.at(i));
		mensajeBinario.push_back(to_string(temp));

		temp = alfabeto.find(clave.at(i));
		claveBinario.push_back(to_string(temp));

		int temp2 = stoi(mensajeBinario[i]);
		bitset<6> a(temp2);
		mensajeBinario[i] = a.to_string();

		temp2 = stoi(claveBinario[i]);
		bitset<6> b(temp2);
		claveBinario[i] = b.to_string();
	}
	for (int i = 0; i < tam; i++) {
		string numero;
		for (int j = 0; j < mensajeBinario[i].length(); j++) {
		   bool temp = (mensajeBinario[i][j] != claveBinario[i][j]);
		   cout<<temp<<endl;
		    string t;
               if(temp==true){
                    t= "1";
                }
                else{
                t= "0";
                }
			numero += t;
		}
		cout << numero << endl;
		cifradoBinario.push_back(numero);
	}
	for(int i=0;i<tam;i++){
        cout<<cifradoBinario[i]<<endl;
        salida << cifradoBinario[i]<<endl;
	}
	return cifradoBinario;
}
string  Vernam::descifrado(vector<string> mensajeBinario ){
	vector<string> bin;

	vector<string> decifradoB;
	string decifrado;
	for (int i = 0; i < tam; i++) {

		int temp = alfabeto.find(clave.at(i));
		bin.push_back(to_string(temp));

		int temp2 = stoi(bin[i]);
		bitset<6> y(temp2);
		bin[i] = y.to_string();
	}

	for (int i = 0; i < tam; i++) {
		string numero;
		for (int j = 0; j < mensajeBinario[i].length(); j++) {
            bool temp = (mensajeBinario[i][j] != bin[i][j]);
		    string t;
               if(temp==true){
                    t= "1";
                }
                else{
                t= "0";
                }
			numero += t;
			cout<<numero<<endl;
		}
        decifradoB.push_back(numero);
		int tem = stoi(decifradoB[i], nullptr, 2);
		cout<<tem<<endl;
		decifrado += alfabeto.at(tem);
	}
for(int i=0;i<tam;i++){
        cout<<decifradoB[i]<<endl;
	}

	return decifrado;

}
Vernam::~Vernam()
{
    //dtor
}
