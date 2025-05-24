#include<bits/stdc++.h>
using namespace std;

// funcao para achar a pos do primeiro numero maoir q x, equivale a qnts tem antes dele
long lb(vector<long>& a, long comp, int n){
    long l = 0;
    long r = n - 1;
    int resp = n;

    while(l <= r){
        long meio = (l+r)/ 2;
        if(a[meio] <= comp){ //descarta a esquerda
            l = meio + 1;
        }
        else{
            resp = meio;
            r = meio - 1; //descarta a direita
        }   
    }

    return resp;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<long> b(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    
    sort(a.begin(), a.end());

    int answ;
    // percorre b pra ve qnts elem de A e menor ou igual (ub)
    for(int i = 0; i < m; i++){
        answ = lb(a,b[i],n);
        cout << answ;
        if (i != m - 1) cout << " ";
    }

    cout << "\n";

    

    return 0;
}