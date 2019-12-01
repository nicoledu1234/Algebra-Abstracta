#include "RC4.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <sstream>
#include <x86intrin.h>
#include <stdlib.h>
#include <string>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

ZZ modulo(ZZ t, ZZ m) {
	ZZ mo ;
	mo=-1;
	if (t < 0)
		return (t * mo >= m) ? (t - (t / m * m)) + m : t + m;
	return (t >= m) ? t - (t / m * m) : t;
}
 ZZ string_a_zz1(string message){
     ZZ number(INIT_VAL, message.c_str());
     return number;
}

RC4::RC4( int bits)
{
    this->bits=bits;
   min=(bits/2)*(bits/2);
   max=bits*bits;

   clave=__rdtsc();
   for(int i=0;i<max;i++){
    s.push_back(conv<ZZ>(i));
    t.push_back(__rdtsc()+clave);
   }
   ZZ j(0);
   for(unsigned int i = min; i<max;i++){
       j = modulo (conv<ZZ>( j + s[i] + t[i] ), conv<ZZ>(bits));
       ZZ tmp=s[i];
       s[i]=s[conv<int>(j)];
       s[conv<int>(j)]=tmp;

    }

   j=0;
   int i=0;
   vector<ZZ> men;
   for(int k=min;k<max;k++){
        i=conv<int>(modulo(conv<ZZ>(i+1),conv<ZZ>(bits)));
        j=modulo (conv<ZZ>( j + s[i]), conv<ZZ>(bits));
        ZZ tmp=s[i];
        s[i]=s[conv<int>(j)];
        s[conv<int>(j)]=tmp;
        int t;
        t=conv<int>(modulo(s[i]+s[conv<int>(j)],conv<ZZ>(bits)));
        men.push_back(s[t]);

   }
   t=men;

}
ZZ RC4::generador (){
    int aleatorio;
    string num;
    for(int i=min;aleatorio<=max;i++){
          int r;
          r=conv<int>(t[i]);
          num+=to_string(r);
          aleatorio=stoi(num);
   }
   cout<<"Aleatorio: ";
   return conv<ZZ>(aleatorio);
}

RC4::~RC4()
{
    //dtor
}
