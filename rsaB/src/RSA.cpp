#include "RSA.h"
#include <NTL/ZZ.h>
#include <time.h>
#include <fstream>
#include "Formulas.h"
#include <sstream>
#include <vector>

using namespace std;
using namespace NTL;


RSA::RSA(int bits) {
 ofstream salida ("claves.txt");
  p = 0;
  q = 0;
  string aa="abcdefghijklm";
  string megaALeatorio;
  string megaALeatorio2;
  for(int i=0; i<10;i++){
    RC4 aa[i](b);
    megaALeatorio+=zz_a_string(aa.generador());
    RC4 bb[i](b);
    megaALeatorio2+=zz_a_string(bb.generador());

  }
 if(fermatTest(10,megaALeatorio)==true){
    p=string_a_zz(megaALeatorio);
 }
else{
     p=RandomPrime_ZZ(bits);
}
 if(fermatTest(10,megaALeatorio2)==true){
    q=string_a_zz(megaALeatorio2);
 }
else{
     p=RandomPrime_ZZ(bits);
}

  n = p * q;
  phiN = (p-1) * (q-1);

  e = RandomBits_ZZ(bits);
  while (euclides(e, phiN) != 1 || e > phiN)
    e++;

  d = getInverse(e, phiN);

  cout << "La clave Publica es: ( e= " << e << ", n= " << n << ")" << endl;
  cout << "La clave Pribada es: ( d= " << d << ", n= " << n << ")" << endl;
  salida<<"Clave Publica :  e= "<<e<<endl;
salida<<"Clave Publica :  N= "<<n<<endl;


  dp = mod(d, p-1);
  dq = mod(d, q-1);
  qCp = mod( getInverse(q, p) * q, n);
  pCq = mod( getInverse(p, q) * p, n);
}

string RSA::encrypt(string text) {
  cout << "Ingresa la clave publica del receptor \n";
  ZZ receiverE, receiverN;
  cin >> receiverE >> receiverN;


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
  nss << receiverN;
  string strN = nss.str();
  unsigned int digitsN = strN.size();
  int i=0;
  while (breakPoint < ciphertext.size()) {
    ZZ block;

    if (digitsN % 2) {
      block = string_a_zz(ciphertext.substr(breakPoint, digitsN+1)/*.c_str()*/);
       cout <<"digitsN % 2 "<< block<< " " <<(ciphertext.substr(breakPoint, digitsN+1)/*.c_str()*/) << endl;
      if (block >= receiverN) {
        block = string_a_zz(ciphertext.substr(breakPoint, digitsN-1)/*.c_str()*/);
        breakPoint += digitsN-1;
        cout <<"digitsN % 2  block >= receiverN "<< block<< " " <<(ciphertext.substr(breakPoint, digitsN-1)) << endl;
      }
      else breakPoint += digitsN+1;
    }
    else {
      block = string_a_zz(ciphertext.substr(breakPoint, digitsN));
       cout <<"else "<< block<< " " <<(ciphertext.substr(breakPoint, digitsN)) << endl;
      if (block >= receiverN) {
        block = string_a_zz(ciphertext.substr(breakPoint, digitsN-1));
        breakPoint += digitsN - 1/*2*/;
         cout <<"else block >= receiverN "<< block<< " " <<(ciphertext.substr(breakPoint, digitsN-1)) << endl;
      }
      else breakPoint += digitsN;
    }
     cout << block << endl;
    blocks.push_back(modularExponentiation(block, receiverE, receiverN));


  }


cout<<"_____________________________________________"<<endl;

  ciphertext.clear();
  for (unsigned int i = 0; i < blocks.size(); i++) {
    stringstream ss;
    ss << blocks[i];

     cout <<" - "<< blocks[i] << endl;
    string strBlock = ss.str();

    if (i > 0)
      while (strBlock.size() < digitsN) strBlock = "0" + strBlock;

    ciphertext += strBlock;
  }

  cout << "\nEl cifrado es: ";
  cout<<ciphertext<<endl;
  return ciphertext;
}

string RSA::decrypt(string cipherNum) {
  stringstream nss;
  nss << n;
  string strN = nss.str();
  unsigned int digitsN = strN.size();

  vector<ZZ> blocks;
  vector<ZZ> blocks2;
 /* for (int i = 0; i < blocks.size(); i++)
     cout << blocks[i] << endl;
     cout<<"______________________"<<endl;*/

  for (unsigned int i = 0; i < cipherNum.size(); i+=digitsN) {
    ZZ block = string_a_zz(cipherNum.substr(i, digitsN));
    cout << block<< endl;
    blocks.push_back(chinese_theorem(block));
  }

  /*for (int i = 0; i < blocks.size(); i++)
     cout << blocks[i] << endl;*/
cout<<"_____________________________________________"<<endl;

  string strRealNum;
  for (unsigned int i = 0; i < blocks.size(); i++) {
    stringstream ss;
    ss << blocks[i];
     cout <<" - "<< blocks[i] << endl;
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

ZZ RSA::chinese_theorem(ZZ cipherNum) {
  ZZ cipherNumP, cipherNumQ, Xp, Xq, Cp, Cq, result;
  cipherNumP = mod(cipherNum, p);
  cipherNumQ = mod(cipherNum, q);

  Xp = modularExponentiation(cipherNumP, dp, p);
  Xq = modularExponentiation(cipherNumQ, dq, q);

  return mod( mod(Xq*pCq, n) + mod(Xp*qCp , n), n);
}

