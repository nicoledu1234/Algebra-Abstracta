#include <iostream>
#include<string>
#include <ctime>

using namespace std;

unsigned long long mod(unsigned long long t, unsigned long long m) {
  unsigned long long mo = -1;
  if (t < 0)
	  return (t*mo >= m) ? (t - (t/m * m)) + m : t+ m;
  return (t >= m) ? t - (t/m * m) : t;
}

unsigned long long mcd(unsigned long long a,unsigned long long b, int &cont){
    unsigned long long r1=a;
    unsigned long long r2=b;
    unsigned t0, t1;
    t0=clock();
    while(r2>0){
        cout<<"a= "<<r1<<"  b= "<<r2<<endl;
        cont++;
        unsigned long long q=r1/r2;
        unsigned long long r=r1-q*r2;
        r1=r2;
        r2=r;
    }
    cout<<"a= "<<r1<<"  b= "<<r2<<endl;
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    cout << "Numero de vueltas: " << cont << endl;
    return r1;
}


unsigned long long algoritmo1(unsigned long long a, unsigned long long b, int &cont){
    unsigned t0, t1;
    t0=clock();
    cont++;
    cout<<"a= "<<a<<"  b= "<<b<<endl;

    unsigned long long r=mod(a,b);
    if (r==0){
        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << "Execution Time: " << time << endl;
        cout << "Numero de vueltas: " << cont << endl;
        return b;

    }
    else{
        a=b;
        b=r;
        algoritmo1(a,b,cont);
    }
}

unsigned long long algoritmo2(unsigned long long a, unsigned long long b, int &cont){
    unsigned t0, t1;
    t0=clock();
    cont++;
    cout<<"a= "<<a<<"  b= "<<b<<endl;
    unsigned long long r=mod(a,b);
    if (r==0){
        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << "Execution Time: " << time << endl;
        cout << "Numero de vueltas: " << cont << endl;
        return b;
    }
    if(r>(b>>1)){
        r=b-r;
    }
    a=b;
    b=r;
    algoritmo2(a,b,cont);
}
unsigned long long EuclidesMCD(unsigned long long a, unsigned long long b,int &cont){
    unsigned t0, t1;
    t0=clock();
    cont++;
    cout<<"a= "<<a<<"  b= "<<b<<endl;
    if(b==0){
        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << "Execution Time: " << time << endl;
        cout << "Numero de vueltas: " << cont << endl;
        return a;
    }
    return EuclidesMCD(b,mod(a,b),cont);
}

unsigned long long BinaryGcd(unsigned long long a, unsigned long long b, int& cont){
    unsigned t0, t1;
    t0=clock();
    cont++;
    cout<<"a= "<<a<<"  b= "<<b<<endl;
    if(b>a){
        return BinaryGcd(b,a,cont);
    }
    if(b==0){
        t1 = clock();
        double time = (double(t1-t0)/CLOCKS_PER_SEC);
        cout << "Execution Time: " << time << endl;
        cout << "Numero de vueltas: " << cont << endl;
        return a;
    }
    if((a&1)==0 && (b&1)==0){
        return (BinaryGcd((a>>1),(b>>1),cont))<<1;
    }
    if((a&1)==0 &&(b&1)==1){
        return BinaryGcd((a>>1),b,cont);
    }
    if((a&1)==1&&(b&1)==0){
        if(a<0){
            a*=-1;
        }
        if(b<0){
            a*=-1;
        }
        return BinaryGcd(a,(b>>1),cont);
    }
    else{
        return BinaryGcd((a-b)>>1,b,cont);
    }
}
unsigned long long algoritmo5(unsigned long long x, unsigned long long y, int &cont){
    unsigned t0, t1;
    t0=clock();
    unsigned long long g=1;
    if(x<0||y<0){
        return 0;
    }
    while((x&1)==0 &&(y&1)==0){
        cont++;
        cout<<"a= "<<x<<"  b= "<<y<<endl;
        x=(x>>1);
        y=(y>>1);
        g=g<<1;
    }

    while(x!=0){
        cout<<"a= "<<x<<"  b= "<<y<<endl;
        cont++;
        while ((x&1)==0){
                cont++;
            x=(x>>1);
        }
        while ((y&1)==0){
            cont++;
            y=(y>>1);
        }
       unsigned long long t;
       long long temp=(x-y);
        if(temp<0){
            t=-1*(temp>>1);
        }
        else{
           t=((x-y)>>1);
        }
         if(temp<0){

            y=t;
         }
         else{
             x=t;
         }
    }
     cout<<"a= "<<x<<"  b= "<<y<<endl;
     t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    cout << "Numero de vueltas: " << cont << endl;
    return(g*y);
}
unsigned long long algoritmo6(unsigned long long a,unsigned long long b, int &cont){
    unsigned t0, t1;
    t0=clock();
    cout<<"a= "<<a<<"  b= "<<b<<endl;
    while(a!=b){
        cont++;
        if(a>b){
            a=a-b;
        }
        else{
            b=b-a;
        }
        cout<<"a= "<<a<<"  b= "<<b<<endl;
    }
     t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    cout << "Numero de vueltas: " << cont << endl;
    return a;
}
int main()
{

      /// 5 cifras Algoritmo 1
    /*
    int cont=0;
    int resultado1a=algoritmo1(88800,36620,cont);
    cout << "Resultado Algoritmo 1 Par-Par: "<<resultado1a << endl;
    int conta=0;
    int resultado1b=algoritmo1(88800,39573,conta);
    cout << "Resultado Algoritmo 1 par- impar : "<<resultado1b << endl;
    int contad=0;
    int resultado1c=algoritmo1(55575,36620,contad);
    cout << "Resultado Algoritmo 1 impar - par: "<<resultado1c << endl;
    int contado=0;
    int resultado1d=algoritmo1(55575,39573,contado);
    cout << "Resultado Algoritmo 1 : impar - impar "<<resultado1d << endl;
    */
    /// 10 cifras Algoritmo 1
    /*
    int cont=0;
    int resultado1a=algoritmo1(1086266082,8624805420,cont);
    cout << "Resultado Algoritmo 1 Par-Par: "<<resultado1a << endl;
    int conta=0;
    int resultado1b=algoritmo1(1086266082,9752375797,conta);
    cout << "Resultado Algoritmo 1 par- impar : "<<resultado1b << endl;
    int contad=0;
    int resultado1c=algoritmo1(1135793597,8624805420,contad);
    cout << "Resultado Algoritmo 1 impar - par: "<<resultado1c << endl;
    int contado=0;
    int resultado1d=algoritmo1(1135793597,9752375797,contado);
    cout << "Resultado Algoritmo 1 : impar - impar "<<resultado1d << endl;
    */

    /// 15 cifras Algoritmo 1

    /*
    int cont=0;
    int resultado1a=algoritmo1(108626608262660,862480542062480,cont);
    cout << "Resultado Algoritmo 1 Par-Par: "<<resultado1a << endl;
    int conta=0;
    int resultado1b=algoritmo1(108626608262660,975237579752375,conta);
    cout << "Resultado Algoritmo 1 par- impar : "<<resultado1b << endl;
    int contad=0;
    int resultado1c=algoritmo1(113579359713575,862480542062480,contad);
    cout << "Resultado Algoritmo 1 impar - par: "<<resultado1c << endl;
    int contado=0;
    int resultado1d=algoritmo1(113579359713575,975237579752375,contado);
    cout << "Resultado Algoritmo 1 : impar - impar "<<resultado1d << endl;
*/
    /// 20 cifras Algoritmo 1
    /*
    int cont=0;
    int resultado1a=algoritmo1(84622648462842624864,64288462648262248628,cont);
    cout << "Resultado Algoritmo 1 Par-Par: "<<resultado1a << endl;
    int conta=0;
    int resultado1b=algoritmo1(84622648462842624864,75713577951319975135,conta);
    cout << "Resultado Algoritmo 1 par- impar : "<<resultado1b << endl;
    int contad=0;
    int resultado1c=algoritmo1(97531315795379951733,64288462648262248628,contad);
    cout << "Resultado Algoritmo 1 impar - par: "<<resultado1c << endl;
    int contado=0;
    int resultado1d=algoritmo1(97531315795379951733,75713577951319975135,contado);
    cout << "Resultado Algoritmo 1 : impar - impar "<<resultado1d << endl;
    */


    /// 5 cifras Algoritmo 2
    /*
    int cont=0;
    int resultado2a=algoritmo2(88800,36620,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo2(88800,39573,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=algoritmo2(55575,36620,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo2(55575,39573,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/

    /// 10 cifras Algoritmo 2
/*
    int cont=0;
    int resultado2a=algoritmo2(1086266082,8624805420,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo2(1086266082,9752375797,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=algoritmo2(1135793597,8624805420,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo2(1135793597,9752375797,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/

    /// 15 cifras Algoritmo 2

/*
    int cont=0;
    int resultado2a=algoritmo2(108626608262660,862480542062480,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo2(108626608262660,975237579752375,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=algoritmo2(113579359713575,862480542062480,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo2(113579359713575,975237579752375,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/

    /// 20 cifras Algoritmo 2
/*
    int cont=0;
    int resultado2a=algoritmo2(84622648462842624864,64288462648262248628,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo2(84622648462842624864,75713577951319975135,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=algoritmo2(97531315795379951733,64288462648262248628,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo2(97531315795379951733,75713577951319975135,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/

        /// 5 cifras Algoritmo 3
/*
    int cont=0;
    int resultado3a=EuclidesMCD(88800,36620,cont);
    cout << "Resultado Algoritmo 3 Par-Par: "<<resultado3a << endl;
    int conta=0;
    int resultado3b=EuclidesMCD(88800,39573,conta);
    cout << "Resultado Algoritmo 3 par- impar : "<<resultado3b << endl;
    int contad=0;
    int resultado3c=EuclidesMCD(55575,36620,contad);
    cout << "Resultado Algoritmo 3 impar - par: "<<resultado3c << endl;
    int contado=0;
    int resultado3d=EuclidesMCD(55575,39573,contado);
    cout << "Resultado Algoritmo 3 : impar - impar "<<resultado3d << endl;
*/

    /// 10 cifras Algoritmo 3
/*
    int cont=0;
    int resultado3a=EuclidesMCD(1086266082,8624805420,cont);
    cout << "Resultado Algoritmo 3 Par-Par: "<<resultado3a << endl;
    int conta=0;
    int resultado3b=EuclidesMCD(1086266082,9752375797,conta);
    cout << "Resultado Algoritmo 3 par- impar : "<<resultado3b << endl;
    int contad=0;
    int resultado3c=EuclidesMCD(1135793597,8624805420,contad);
    cout << "Resultado Algoritmo 3 impar - par: "<<resultado3c << endl;
    int contado=0;
    int resultado3d=EuclidesMCD(1135793597,9752375797,contado);
    cout << "Resultado Algoritmo 3 : impar - impar "<<resultado3d << endl;
*/

    /// 15 cifras Algoritmo 3

/*
    int cont=0;
    int resultado3a=EuclidesMCD(108626608262660,862480542062480,cont);
    cout << "Resultado Algoritmo 3 Par-Par: "<<resultado3a << endl;
    int conta=0;
    int resultado3b=EuclidesMCD(108626608262660,975237579752375,conta);
    cout << "Resultado Algoritmo 3 par- impar : "<<resultado3b << endl;
    int contad=0;
    int resultado3c=EuclidesMCD(113579359713575,862480542062480,contad);
    cout << "Resultado Algoritmo 3 impar - par: "<<resultado3c << endl;
    int contado=0;
    int resultado3d=EuclidesMCD(113579359713575,975237579752375,contado);
    cout << "Resultado Algoritmo 3 : impar - impar "<<resultado3d << endl;

*/
    /// 20 cifras Algoritmo 3
/*
    int cont=0;
    int resultado3a=EuclidesMCD(84622648462842624864,64288462648262248628,cont);
    cout << "Resultado Algoritmo 3 Par-Par: "<<resultado3a << endl;
    int conta=0;
    int resultado3b=EuclidesMCD(84622648462842624864,75713577951319975135,conta);
    cout << "Resultado Algoritmo 3 par- impar : "<<resultado3b << endl;
    int contad=0;
    int resultado3c=EuclidesMCD(97531315795379951733,64288462648262248628,contad);
    cout << "Resultado Algoritmo 3 impar - par: "<<resultado3c << endl;
    int contado=0;
    int resultado3d=EuclidesMCD(97531315795379951733,75713577951319975135,contado);
    cout << "Resultado Algoritmo 3 : impar - impar "<<resultado3d << endl;
*/


        /// 5 cifras Algoritmo 4
/*
    int cont=0;
    int resultado4a=BinaryGcd(88800,36620,cont);
    cout << "Resultado Algoritmo 4 Par-Par: "<<resultado4a << endl;
    int conta=0;
    int resultado4b=BinaryGcd(88800,39573,conta);
    cout << "Resultado Algoritmo 4 par- impar : "<<resultado4b << endl;
    int contad=0;
    int resultado4c=BinaryGcd(55575,36620,contad);
    cout << "Resultado Algoritmo 4 impar - par: "<<resultado4c << endl;
    int contado=0;
    int resultado4d=BinaryGcd(55575,39573,contado);
    cout << "Resultado Algoritmo 4 : impar - impar "<<resultado4d << endl;
*/
    /// 10 cifras Algoritmo 4
/*
    int cont=0;
    int resultado4a=BinaryGcd(1086266082,8624805420,cont);
    cout << "Resultado Algoritmo 4 Par-Par: "<<resultado4a << endl;
    int conta=0;
    int resultado4b=BinaryGcd(1086266082,9752375797,conta);
    cout << "Resultado Algoritmo 4 par- impar : "<<resultado4b << endl;
    int contad=0;
    int resultado4c=BinaryGcd(1135793597,8624805420,contad);
    cout << "Resultado Algoritmo  impar - par: "<<resultado4c << endl;
    int contado=0;
    int resultado4d=BinaryGcd(1135793597,9752375797,contado);
    cout << "Resultado Algoritmo 4 : impar - impar "<<resultado4d << endl;
*/

    /// 15 cifras Algoritmo 4

/*
    int cont=0;
    int resultado4a=BinaryGcd(108626608262660,862480542062480,cont);
    cout << "Resultado Algoritmo 4 Par-Par: "<<resultado4a << endl;
    int conta=0;
    int resultado4b=BinaryGcd(108626608262660,975237579752375,conta);
    cout << "Resultado Algoritmo 4 par- impar : "<<resultado4b << endl;
    int contad=0;
    int resultado4c=BinaryGcd(113579359713575,862480542062480,contad);
    cout << "Resultado Algoritmo 4 impar - par: "<<resultado4c << endl;
    int contado=0;
    int resultado4d=BinaryGcd(113579359713575,975237579752375,contado);
    cout << "Resultado Algoritmo 4 : impar - impar "<<resultado4d << endl;
*/

    /// 20 cifras Algoritmo 4
 /*
    int cont=0;
    int resultado4a=BinaryGcd(84622648462842624864,64288462648262248628,cont);
    cout << "Resultado Algoritmo 4 Par-Par: "<<resultado4a << endl;
    int conta=0;
    int resultado4b=BinaryGcd(84622648462842624864,75713577951319975135,conta);
    cout << "Resultado Algoritmo 4 par- impar : "<<resultado4b << endl;
  int contad=0;
    int resultado4c=BinaryGcd(97531315795379951733,64288462648262248628,contad);
    cout << "Resultado Algoritmo 4 impar - par: "<<resultado4c << endl;
    int contado=0;
    int resultado4d=BinaryGcd(97531315795379951733,75713577951319975135,contado);
    cout << "Resultado Algoritmo 4 : impar - impar "<<resultado4d << endl;
*/

    /// 5 cifras Algoritmo 5
/*
    int cont=0;
    int resultado2a=algoritmo5(88800,36620,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo5(88800,39573,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=algoritmo5(55575,36620,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo5(55575,39573,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/

    /// 10 cifras Algoritmo 5
/*
    int cont=0;
    int resultado2a=algoritmo5(1086266082,8624805420,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo5(1086266082,9752375797,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=algoritmo5(1135793597,8624805420,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo5(1135793597,9752375797,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/

    /// 15 cifras Algoritmo 5
/*

    int cont=0;
    int resultado2a=algoritmo5(108626608262660,862480542062480,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo5(108626608262660,975237579752375,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=algoritmo5(113579359713575,862480542062480,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo5(113579359713575,975237579752375,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;

*/
    /// 20 cifras Algoritmo 5
/*
    int cont=0;
    int resultado2a=algoritmo5(84622648462842624864,64288462648262248628,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo5(84622648462842624864,75713577951319975135,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=algoritmo5(97531315795379951733,64288462648262248628,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo5(97531315795379951733,75713577951319975135,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/



    /// 5 cifras Algoritmo 6
/*
    int cont=0;
    int resultado2a=algoritmo6(88800,36620,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo6(88800,39573,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=algoritmo6(55575,36620,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo6(55575,39573,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/

    /// 10 cifras Algoritmo 6

   /* int cont=0;
    int resultado2a=algoritmo6(1086266082,8624805420,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo6(1086266082,9752375797,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=algoritmo6(1135793597,8624805420,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo6(1135793597,9752375797,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/

    /// 15 cifras Algoritmo 6
/*

    int cont=0;
    int resultado2a=algoritmo6(108626608262660,862480542062480,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo6(108626608262660,975237579752375,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
   int contad=0;
    int resultado2c=algoritmo6(113579359713575,862480542062480,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo6(113579359713575,975237579752375,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/

    /// 20 cifras Algoritmo 6

/*    int cont=0;
    int resultado2a=algoritmo6(84622648462842624864,64288462648262248628,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=algoritmo6(84622648462842624864,75713577951319975135,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
  int contad=0;
int resultado2c=algoritmo6(97531315795379951733,64288462648262248628,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
   int contado=0;
    int resultado2d=algoritmo6(97531315795379951733,75713577951319975135,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/


    /// 5 cifras Algoritmo 7
/*
    int cont=0;
    int resultado2a=mcd(88800,36620,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=mcd(88800,39573,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=mcd(55575,36620,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=mcd(55575,39573,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/

    /// 10 cifras Algoritmo 7
/*
   int cont=0;
    int resultado2a=mcd(1086266082,8624805420,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=mcd(1086266082,9752375797,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
    int contad=0;
    int resultado2c=mcd(1135793597,8624805420,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=mcd(1135793597,9752375797,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;

*/
    /// 15 cifras Algoritmo 6
/*
    int cont=0;
    int resultado2a=mcd(108626608262660,862480542062480,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=mcd(108626608262660,975237579752375,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
   int contad=0;
    int resultado2c=mcd(113579359713575,862480542062480,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=mcd(113579359713575,975237579752375,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;

*/
    /// 20 cifras Algoritmo 7
/*
   int cont=0;
    int resultado2a=mcd(84622648462842624864,64288462648262248628,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
    int conta=0;
    int resultado2b=mcd(84622648462842624864,75713577951319975135,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
  int contad=0;
int resultado2c=mcd(97531315795379951733,64288462648262248628,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
   int contado=0;
    int resultado2d=mcd(97531315795379951733,75713577951319975135,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
    */
        /// 15 cifras Algoritmo 6


    int cont=0;
    int resultado2a=algoritmo6(108626608262660,862480542062480,cont);
    cout << "Resultado Algoritmo 2 Par-Par: "<<resultado2a << endl;
  /*  int conta=0;
    int resultado2b=algoritmo6(108626608262660,975237579752375,conta);
    cout << "Resultado Algoritmo 2 par- impar : "<<resultado2b << endl;
   int contad=0;
    int resultado2c=algoritmo6(113579359713575,862480542062480,contad);
    cout << "Resultado Algoritmo 2 impar - par: "<<resultado2c << endl;
    int contado=0;
    int resultado2d=algoritmo6(113579359713575,975237579752375,contado);
    cout << "Resultado Algoritmo 2 : impar - impar "<<resultado2d << endl;
*/
    return 0;
}

