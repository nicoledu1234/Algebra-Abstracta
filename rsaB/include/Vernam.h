#ifndef VERNAM_H
#define VERNAM_H
#include <iostream>
#include <ctime>
#include <iostream>
#include <ctime>
#include <bitset>
#include <vector>
#include <cstdlib>
#include <string>
#include <math.h>
#include <cstring>
#include <stdlib.h>

using namespace std;
class Vernam
{
private:
	string clave;
	//string claveNum[string];
public:
	string alfabeto = "abcdefghijklmnopqrstuvwxyz0123456789 ";
	int tamAlfabeto = alfabeto.length();
	int tam;
	//string mensajeNum[37];
	Vernam(int tam);
	Vernam(string clave);
	vector<string> cifrado(string mensaje);
	string descifrado(vector<string> mensaje);
	virtual ~Vernam();

protected:

private:
};

#endif // VERNAM_H
