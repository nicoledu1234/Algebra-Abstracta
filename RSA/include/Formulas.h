#include <iostream>
#include<string>
#include <ctime>
#include<vector>
#include <cstdlib>
#include "Vernam.h"
using namespace std;

int mod(int t, int m) {
	int mo = -1;
	if (t < 0)
		return (t * mo >= m) ? (t - (t / m * m)) + m : t + m;
	return (t >= m) ? t - (t / m * m) : t;
}

int generadorAleatorios(int maximo) {
	srand(time(NULL));
	int aleatorio, DESDE = 0, HASTA = maximo;
	aleatorio = mod(rand(), HASTA);
	return aleatorio;
}
string generadorMensajeAleatorio(int tam, string alf, int alfabetoTam) {
	string mensajeAleatorio;
	for (int i = 0; i < tam; i++) {
		int aleatorio = generadorAleatorios(alfabetoTam-1);
		//cout<<"aleatorio"<< aleatorio<<endl;
		mensajeAleatorio+= alf.at(aleatorio);
		alf.erase(aleatorio, 1);
	}
	return mensajeAleatorio;
}
unsigned long long euclides(unsigned long long a, unsigned long long b) {
    unsigned long long r1 = a;
	unsigned long long r2 = b;
	while (r2 > 0) {
		unsigned long long q = r1 / r2;
		unsigned long long r = r1 - q * r2;
		r1 = r2;
		r2 = r;
	}
	//cout<<"El Maximo Comun Divisor es: "<<r1<<endl;
	return r1;
}

vector<unsigned long long> EuclidesExtendido(unsigned long long a, unsigned long long b) {
	unsigned long long r1 = a;
	unsigned long long r2 = b;
	unsigned long long s1 = 1;
	unsigned long long s2 = 0;
    unsigned long long t1 = 0;
	unsigned long long t2 = 1;
	while (r2 > 0) {
		unsigned long long q = r1 / r2;
		unsigned long long r = r1 - q * r2;
		r1 = r2;
		r2 = r;

		unsigned long long s = s1 - q * s2;
		s1 = s2;
		s2 = s;

		unsigned long long t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	vector<unsigned long long> ee = { s1,t1,r1 };
	/*cout<<"El valor de x:"<<s1<<endl;
	cout<<"El valor de y: "<<t1<<endl;
	cout<<r1<<"="<<"("<<s1<<")*"<<a<<"+"<<"("<<t1<<")*"<<b<<endl;*/
	return ee;
}
unsigned long long inversoMod(unsigned long long a, unsigned long long m) {
	vector<unsigned long long> tm = EuclidesExtendido(a, m);
	unsigned long long g = tm[2];
	unsigned long long x = tm[0];
	unsigned long long y = tm[1];
	if (g != 1) {
		cout << "No existe el inverso modular" << endl;
		return 0;
	}
	else {
		unsigned long long res = mod((mod(x, m) + m), m);
		//cout << "la inversa es: " << res << endl;
		return res;
	}
}


unsigned long long ExponenciacionModular(unsigned long long num, unsigned long long e, unsigned long long mo) {
	unsigned long long resMod = mod(num, mo);
	unsigned long long res = mod(num, mo);
	e = (e >> 1);
    unsigned long long temp = res;
	for (unsigned long long  n = 2; e > 0; e = (e >> 1), n++) {
		temp = mod(temp * mod(temp, mo), mo);
		if ((e & 1) == 1) {
			res = temp;
			resMod = mod(resMod * mod(res, mo), mo);
		}
	}
	return resMod;
}


vector<unsigned long long> CribaDeEratostenes(int n) {
	vector<bool> primos;
	vector<unsigned long long> nPrimos;
	for (int i = 0; i <= n; i++) {
		primos.push_back(true);
	}
	primos[0] = false;
	primos[1] = false;
	for (unsigned long long i = 2; i * i <= n; i++) {
		if (primos[i] == true) {
			for (int j = i * i; j <= n; j += i)
				primos[j] = false;
		}
	}
	//cout << " Los primos menores a " << n << " son : [";
	for (unsigned long long p = 0; p <= n; p++) {
		if (primos[p]) {
			nPrimos.push_back(p);
			//  cout << p << " , ";
		  //  cout << nPrimos[]<< " , ";

		}
		//cout << nPrimos[p]<< " , ";
	}

	/*for (int i = 0; i < nPrimos.size(); i++) {
		cout << nPrimos[i] << " , ";
	}
	cout << " ]" << endl;*/
	return nPrimos;
}


void generadorClaves(unsigned long long &p ,unsigned long long &q) {
	int tam = 10;
	/*if ((tam & 1) != 1) {
		tam += 1;
	}*/
	cout<<"tam "<< tam<<endl;
	Vernam gg(tam);
  //cout<<"tam "<< tam<<endl;
	vector<string> binarios = gg.cifrado(generadorMensajeAleatorio(tam, gg.alfabeto, gg.tamAlfabeto));
	string aString;
	aString += binarios[1];
	aString += binarios[2];
    //cout << "aString   "<<aString << endl;
	string bString;
	bString += binarios[3];
	bString += binarios[4];
	//cout << "bString   "<<bString << endl;
	unsigned long long a;
	unsigned long long b;

	a= stoi(aString, nullptr, 2);
	//cout << "a "<<a << endl;
	b = stoi(bString, nullptr, 2);
	//cout << "b "<<b << endl;

	vector<unsigned long long> criba;
	criba=CribaDeEratostenes(9999999);
	p = criba[a];
	q = criba[b];
    //cout << "p  " << p << endl;
	//cout << "q  " << q << endl;
/*
	vector<unsigned long long> primos;
	cout<<"rrr"<<endl;
	primos[0] = 8925;
	primos[1] = 65261;
	cout << "p  " << primos[0] << endl;
	cout << "q  " << primos[1]<< endl;
	return primos;*/

}
