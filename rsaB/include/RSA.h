#ifndef RSA_H
#define RSA_H

#include <NTL/ZZ.h>
using namespace NTL;

class RSA {
  private:
    ZZ e, n, p, q, phiN, d, dp, dq, qCp, pCq;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ012345679-";
  public:
    RSA(int);
    virtual ~RSA(){}
    std::string encrypt(std::string);
    std::string decrypt(std::string);
    ZZ chinese_theorem(ZZ);
    ZZ fast_exponentiation(ZZ, ZZ, ZZ);
    ZZ gen_rand(int);
};

#endif // RSA_H
