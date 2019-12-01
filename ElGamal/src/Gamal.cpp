#include "Formulas.h"
#include "Gamal.h"
#include "RC4.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <RC4.h>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

Gamal::Gamal(int b)
{
  bits=b;
  ofstream salida ("claves.txt");

  string aa="abcdefghijklm";
  string megaALeatorio;
  for(int i=0; i<10;i++){
    RC4 aa[i](b);
    megaALeatorio+=zz_a_string(aa.generador());
  }
 if(fermatTest(10,megaALeatorio)==true){
    p=string_a_zz(megaALeatorio);
 }
else{
     p=RandomPrime_ZZ(bits);
}

  cout<<"p  "<<p<<endl;

  e1=generarRaiz(p);
   cout<<"e1 "<<e1<<endl;
   d=RandomBits_ZZ(bits);
    cout<<"d "<<d<<endl;
   e2=ExponenciacionModular(e1,d,p);
    cout<<"e2 "<<e2<<endl;
    cout<<endl;
    cout<<"Clave Publica : ( e1= "<<e1<<" , e2= "<<e2<<" , p= "<<p<<" )"<<endl;
    cout<<"Clave Privada : (  d= " << d<<" )"<<endl;
salida<<"Clave Publica : ( e1= "<<e1<<endl;
salida<<"Clave Publica :  e2= "<<e2<<endl;
salida<<"Clave Publica :  p= "<<p<<endl;

}
ZZ Gamal::generarRaiz(ZZ primo){
    ZZ g,c,q;
    q=(p-1)/2;
    c=2;
    for(int i=1;i<p-1;i++){
        g=primo-i;
        if((ExponenciacionModular(g,c,p)!=1)&&(ExponenciacionModular(g,q,p)!=1)){
            return g;
        }
    }
    return g;
}
vector<ZZ> Gamal::generarRaices(ZZ primo){
    vector<ZZ> generadores;
    ZZ cont, base;
    base=1;
    ZZ i,a;
    while(base<primo){
        cont=0;
        for(i=1;i<primo;i++){
            a= ExponenciacionModular(base,i,primo);
            //cout<<a<<" ";
            if(a!=1){
                cont++;
            }
            else{
                break;
            }
        }
        if(cont==primo-2){
            generadores.push_back(base);
            break;
        }
        base++;
    }

    return generadores;
}
vector<string> Gamal::cifrado(string text) {
  cout << "Ingresa la clave publica del receptor \n";
  ZZ receiverE1,receiverE2, receiverP;
  cin >> receiverE1>> receiverE2 >> receiverP;
  ZZ r;
  r=RandomBits_ZZ(bits);
  ZZ c1;
  c1=ExponenciacionModular(receiverE1,r,receiverP);
  ZZ km;
  km=ExponenciacionModular(receiverE2,r,receiverP);
  cout<<"r "<<r<<" c1 "<<c1<<" km "<<km<<endl;
  stringstream tt;
    tt <<c1;
    string strc1 = tt.str();

   vector<string> cif;
   cif.push_back(strc1);


  string ciphertext;
  for (unsigned short int i = 0; i < text.size(); i++) {
    unsigned short int num = alphabet.find(text[i]);
    string strNum;
    if (num < 10)
      strNum = "0" + to_string(num);
    else
      strNum = to_string(num);
    ciphertext += strNum;
  }
  vector<ZZ> blocks;
  unsigned int breakPoint = 0;
  stringstream nss;
  nss << receiverP;
  string strN = nss.str();
  unsigned int digitsN = strN.size();
  while (breakPoint < ciphertext.size()) {
    ZZ block;
    if (digitsN % 2) {
      block = string_a_zz(ciphertext.substr(breakPoint, digitsN+1));
      if (block >= receiverP) {
        block = string_a_zz(ciphertext.substr(breakPoint, digitsN-1));
        breakPoint += digitsN-1;
      }
      else breakPoint += digitsN+1;
    }
    else {
      block = string_a_zz(ciphertext.substr(breakPoint, digitsN));
      if (block >= receiverP) {
        block = string_a_zz(ciphertext.substr(breakPoint, digitsN-2));
        breakPoint += digitsN - 2;
      }
      else breakPoint += digitsN;
    }
    blocks.push_back(mod(block*km,receiverP));
  }

  ciphertext.clear();
  for (unsigned int i = 0; i < blocks.size(); i++) {
    stringstream ss;
    ss << blocks[i];
    string strBlock = ss.str();

    if (i > 0)
      while (strBlock.size() < digitsN) strBlock = "0" + strBlock;

    ciphertext += strBlock;
  }
cif.push_back(ciphertext);
  cout << "El cifrado es: ";
  cout<<ciphertext<<endl;
  return cif;

}
string Gamal::descifrado(vector<string> cipherNumvec) {
  ZZ c1;
  c1=string_a_zz(cipherNumvec[0]);
  ZZ km;
  km=ExponenciacionModular(c1,d,p);
    ZZ kmInv;
  kmInv=getInverse(km,p);
  string cipherNum=cipherNumvec[1];
  cout<<"c1 "<<c1<<" km "<<km<<" kmInv "<<kmInv<< " c2 "<<cipherNum<<endl;
  stringstream nss;
  nss << p;
  string strN = nss.str();
  unsigned int digitsN = strN.size();

  vector<ZZ> blocks;
  vector<ZZ> blocks2;


  for (unsigned int i = 0; i < cipherNum.size(); i+=digitsN) {
    ZZ block = conv<ZZ>(cipherNum.substr(i, digitsN).c_str());
    blocks.push_back(mod(block*kmInv,p));
  }

  string strRealNum;
  for (unsigned int i = 0; i < blocks.size(); i++) {
    stringstream ss;
    ss << blocks[i];
    string strBlock = ss.str();

    if (strBlock.size() % 2) strBlock = "0" + strBlock;

    strRealNum += strBlock;
  }

  string text;
  for (unsigned int i = 0; i < strRealNum.size(); i+=2) {
    string strNum = strRealNum.substr(i,2);
    unsigned short int num = stoi(strNum);
    text += alphabet[num];
  }

  return text;
}

Gamal::~Gamal()
{
    //dtor
}
