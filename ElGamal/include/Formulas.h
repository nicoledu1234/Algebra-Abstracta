#include<string>
#include <ctime>
#include<vector>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

ZZ mod(ZZ t, ZZ m) {
	ZZ mo ;
	mo=-1;
	if (t < 0)
		return (t * mo >= m) ? (t - (t / m * m)) + m : t + m;
	return (t >= m) ? t - (t / m * m) : t;
}
int modulo(int t, int m) {
	int mo=-1 ;
	if (t < 0)
		return (t * mo >= m) ? (t - (t / m * m)) + m : t + m;
	return (t >= m) ? t - (t / m * m) : t;
}

int generadorAleatorios(int maximo) {
	srand(time(NULL));
	int aleatorio, DESDE = 0, HASTA = maximo;
	aleatorio = modulo(rand(), HASTA);
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
ZZ euclides(ZZ a, ZZ b) {
    ZZ r1 = a;
	ZZ r2 = b;
	while (r2 > 0) {
		ZZ q = r1 / r2;
		ZZ r = r1 - q * r2;
		r1 = r2;
		r2 = r;
	}
	//cout<<"El Maximo Comun Divisor es: "<<r1<<endl;
	return r1;
}

vector<ZZ> EuclidesExtendido(ZZ a, ZZ b) {
	ZZ r1 = a;
	ZZ r2 = b;
	ZZ s1 ;
	s1 = 1;
	ZZ s2 ;
	s2 = 0;
    ZZ t1 ;
    t1 = 0;
	ZZ t2 ;
	t2 = 1;
	while (r2 > 0) {
		ZZ q = r1 / r2;
		ZZ r = r1 - q * r2;
		r1 = r2;
		r2 = r;

		ZZ s = s1 - q * s2;
		s1 = s2;
		s2 = s;

		ZZ t = t1 - q * t2;
		t1 = t2;
		t2 = t;
	}
	vector<ZZ> ee = { s1,t1,r1 };
	/*cout<<"El valor de x:"<<s1<<endl;
	cout<<"El valor de y: "<<t1<<endl;
	cout<<r1<<"="<<"("<<s1<<")*"<<a<<"+"<<"("<<t1<<")*"<<b<<endl;*/
	return ee;
}

ZZ getInverse(ZZ a, ZZ m) {
  ZZ tmp(m);
  ZZ s0(1), s1;
  while (m > 0) {
    ZZ q, s, r;
    q = a / m;
    r = a - (m * q);
    s = s0 - s1 * q;
    a = m;
    m = r;
    s0 = s1;
    s1 = s;
  }
  ZZ res = mod(s0, tmp);
  return res;
}

ZZ string_a_zz(string message){
     ZZ number(INIT_VAL, message.c_str());
     return number;
}
string zz_a_string(const ZZ &z)
{
  std::stringstream buffer;
  buffer << z;
  return buffer.str();
}
ZZ ExponenciacionModular(ZZ a, ZZ e, ZZ n) {
  ZZ total;
  total = 1;
  ZZ sqrValue = mod(a, n);
  for(int i = 0; e > 0; i++, e >>= 1) {
    if ( mod(e, (ZZ)2) == (ZZ)1)
      total = mod(total*sqrValue, n);

    sqrValue = mod(sqrValue*sqrValue, n);
  }

  return total;
}

vector<ZZ> CribaDeEratostenes(int in, int fi) {
    int u = 0;
    vector<bool> marcas;
    for (int i = in; i <= fi*2; i++) {
        marcas.push_back(true);
    }
    for (int i = 2; i * i <= fi*2; i++) {
        if (marcas[u]) {
            for (int j = 2; i * j <= fi; j++) {
                if ((i * j) >= in) {
                    marcas[(i * j) - in] = false;
                }
            }
        }
        ++u;
    }
    vector<ZZ> numeros;
    for (int i = 0; i < marcas.size(); i++) {
        if (marcas[i] == true) {
            numeros.push_back(ZZ(i + in));
        }
    }
   /* for (int i = 589999; i < 600000; i++) {
        cout<<numeros[i]<<endl;
    }
    */

    return numeros;
}

inline ZZ convBitsToZZ(string bitsStr){
  ZZ conversion;
  for(int i = bitsStr.size(); i >= 0 ; i--)
    if (bitsStr[i] == '1') conversion += power2_ZZ(i);

  return conversion;
}

ZZ convertirBinaryToZZ(string binary)
{
	ZZ res;
	ZZ base;
	base = 2;
	res = 0;
	long exp = 0;
	for (long i = binary.size() - 1; i >= 0; --i) {
		if (binary[i] == '1') {
			res += power(base, exp);
		}
		++exp;
	}

	return res;
}
bool fermatTest(int numTests, string pPrime) {
	ZZ a;
	string binario;
   binario = pPrime;
   ZZ pseudoPrime;
   pseudoPrime= string_a_zz(pPrime);
	if (pseudoPrime == 1)
	{
		return false;
	}
	for (int i = 0; i < numTests; i++)
	{


		a = mod(convertirBinaryToZZ(binario), (pseudoPrime - conv<ZZ>(1)) + conv<ZZ>(1));
		if (ExponenciacionModular(a, pseudoPrime - 1, pseudoPrime) != 1)
		{
			return false;
		}
	}
	return true;
}

ZZ RestoChino(vector< vector <ZZ> >  vec,int n){
    vector< vector <ZZ> >aux=vec;
    ZZ M(1);
    for(int i=0;i<n;i++){
        if(vec[i][0]!=1){
            ZZ tm=getInverse(vec[i][0],vec[i][2]);
            vec[i][0]=mod(vec[i][0]*tm,vec[i][2]);
            vec[i][1]=mod(vec[i][1]*tm,vec[i][2]);
       //     cout<<" vec[i][0] = "<<"vec[i][1] mod  vec[i][2] "<<endl;
       //     cout<<vec[i][0]  <<" = "<<vec[i][1] <<" mod " <<vec[i][2]<<endl;
        }
        M*=vec[i][2];
    }
   // cout<<"M  =  "<<M<<endl;
    for(int i=0;i<n;i++){
        aux[i][2]=M/vec[i][2];
     //   cout<<"m"<<i<< " " <<aux[i][2]<<endl;
        aux[i][0]=getInverse(aux[i][2],vec[i][2]);
      //   cout<<"q"<<i<< " " <<aux[i][0]<<endl;
    }
    ZZ resp(0);
    for(int i=0;i<n;i++){
        ZZ tm(1);
        tm=aux[i][0]*aux[i][1]*aux[i][2];
     //   cout<<"tm = "<<"aux[i][0] * aux[i][1] * aux[i][2] "<<endl;
     //   cout<<tm <<" "<<aux[i][0] <<" * "<< aux[i][1] <<" * " <<aux[i][2]<<endl;
        resp+=mod(tm,M);
    }
    resp=mod(resp,M);
    return resp;
}
