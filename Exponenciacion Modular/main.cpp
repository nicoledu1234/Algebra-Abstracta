#include <iostream>

using namespace std;
int mod(int t, int m) {
  int mo = -1;
  if (t < 0)
	  return (t*mo >= m) ? (t - (t/m * m)) + m : t+ m;
  return (t >= m) ? t - (t/m * m) : t;
}

int ExponenciacionModular(int num, int e, int mo){
    int resMod=mod(num,mo);
    int res=mod(num, mo);
    e=(e>>1);
    int temp=res;
    for(int n=2;e>0;e=(e>>1), n++){
        //temp*=mod(temp,mo);
        temp=mod(temp*mod(temp,mo),mo);
       if(e&1==1){
        res=temp;
            //resMod*=(mod(res,mo));
            resMod=mod(resMod*mod(res,mo),mo);
        }
    }
  return resMod;
}
int main()
{
    cout << ExponenciacionModular(412,25,658) << endl;
    return 0;
}
