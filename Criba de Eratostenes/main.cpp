#include <bits/stdc++.h>
using namespace std;

vector<int> CribaDeEratostenes(int n){
    vector<bool> primos;
    vector<int> nPrimos;
    for(int i=0;i<=n;i++){
        primos.push_back(true);
    }
    primos[0]=false;
    primos[1]=false;
    for (int i=2; i*i<=n; i++){
        if (primos[i] == true){
            for (int j=i*i; j<=n; j += i)
                primos[j] = false;
        }
    }
    cout<<" Los primos menores a "<<n<< " son : [";
    for (int p=0; p<=n; p++){
        if (primos[p]){
          nPrimos.push_back(p);
        //  cout << p << " , ";
      //  cout << nPrimos[]<< " , ";

       }
        //cout << nPrimos[p]<< " , ";
    }

    for(int i=0;i<nPrimos.size();i++){
        cout << nPrimos[i]<< " , ";
    }
    cout<<" ]"<<endl;
    return nPrimos;
}
int main()
{
    int n = 7777;
    vector<int> copia=CribaDeEratostenes(n);
    return 0;
}
