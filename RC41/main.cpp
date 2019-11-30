#include <iostream>
#include <fstream>
#include "RC4.h"
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

int main()
{
string aa="abcdefghijklm";
for(int i=0; i<10;i++){
    RC4 aa[i](1024);
   cout<< aa[i].generador()<<endl;
}
return 0;
}
