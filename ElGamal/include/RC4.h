#ifndef RC4_H
#define RC4_H
#include <iostream>
#include <vector>
#include <string>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

class RC4
{
    public:
        vector<ZZ> s;
        vector<ZZ> t;
        RC4(int bits);
        int bits;
        int min;
        int max;
        ZZ generador ();
        ZZ convertirBinaryToZZ(string binary);
        string convertirBits(vector<string> a);
        virtual ~RC4();

    protected:

    private:
        ZZ clave;
        string keyStream;
};

#endif // RC4_H
