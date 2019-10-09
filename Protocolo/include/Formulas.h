#include <iostream>
#include<string>
#include <ctime>
#include<vector>
#include <cstdlib>
using namespace std;

int mod(int t, int m) {
  int mo = -1;
  if (t < 0)
	  return (t*mo >= m) ? (t - (t/m * m)) + m : t+ m;
  return (t >= m) ? t - (t/m * m) : t;
}

int generadorAleatorios(int maximo){
    srand(time(NULL));
    int aleatorio, DESDE=0, HASTA=maximo;
    aleatorio = mod(rand(),HASTA);
    return aleatorio;
}
int euclides(int a,int b){
    int r1=a;
    int r2=b;
    while(r2>0){
        int q=r1/r2;
        int r=r1-q*r2;
        r1=r2;
        r2=r;
    }
    //cout<<"El Maximo Comun Divisor es: "<<r1<<endl;
    return r1;
}

vector<int> EuclidesExtendido(int a , int b){
    int r1=a;
    int r2=b;
    int s1=1;
    int s2 =0;
    int t1=0;
    int t2=1;
    while(r2>0){
        int q=r1/r2;
        int r=r1-q*r2;
        r1=r2;
        r2=r;

        int s=s1-q*s2;
        s1=s2;
        s2=s;

        int t=t1-q*t2;
        t1=t2;
        t2=t;
    }
    vector<int> ee={s1,t1,r1};
    /*cout<<"El valor de x:"<<s1<<endl;
    cout<<"El valor de y: "<<t1<<endl;
    cout<<r1<<"="<<"("<<s1<<")*"<<a<<"+"<<"("<<t1<<")*"<<b<<endl;*/
    return ee;
}
int inversoMod(int a, int m){
    vector<int> tm=EuclidesExtendido(a,m);
    int g =tm[2];
    int x=tm[0];
    int y=tm[1];
    if (g != 1){
        //cout << "No existe el inverso modular" << endl;
        return 0;
    }
    else{
        int res = mod((mod(x,m)+ m) , m);
         // cout << "la inversa es: "<<res << endl;
        return res;
    }
}
