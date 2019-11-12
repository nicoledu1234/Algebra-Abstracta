#include "RSA.h"
#include <NTL/ZZ.h>
#include <time.h>
#include "Formulas.h"
#include <sstream>
#include <vector>

using namespace std;
using namespace NTL;


RSA::RSA(int bits) {
 
  p = 0;
  q = 0;
  while (p == q) {
 
    generadorClaves(p,q);
  }
  n = p * q;
  phiN = (p-1) * (q-1);

  e = RandomBits_ZZ(bits);
  while (euclides(e, phiN) != 1 || e > phiN)
    e++;

  d = getInverse(e, phiN);

  cout << "La clave Publica es: ( e= " << e << ", n= " << n << ")" << endl;
  cout << "La clave Pribada es: ( d= " << d << ", n= " << n << ")" << endl;

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
    unsigned short int num = alphabet.find(text[i])+2;
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
  while (breakPoint < ciphertext.size()) {
    ZZ block;
    if (digitsN % 2) {
      block = conv<ZZ>(ciphertext.substr(breakPoint, digitsN+1).c_str());
      if (block >= receiverN) {
        block = conv<ZZ>(ciphertext.substr(breakPoint, digitsN-1).c_str());
        breakPoint += digitsN-1;
      }
      else breakPoint += digitsN+1;
    }
    else {
      block = conv<ZZ>(ciphertext.substr(breakPoint, digitsN).c_str());
      if (block >= receiverN) {
        block = conv<ZZ>(ciphertext.substr(breakPoint, digitsN-2).c_str());
        breakPoint += digitsN - 2;
      }
      else breakPoint += digitsN;
    }

    blocks.push_back(modularExponentiation(block, receiverE, receiverN));
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

  cout << "El cifrado es: ";
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
  for (unsigned int i = 0; i < cipherNum.size(); i+=digitsN) {
    ZZ block = conv<ZZ>(cipherNum.substr(i, digitsN).c_str());
    blocks.push_back(chinese_theorem(block));
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
    text += alphabet[num-2];
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

}

