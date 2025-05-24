#include<bits/stdc++.h>
using namespace std;

int lb(int ogro, vector<int>& faixas, int n){
    int l = 0, r = n-2;
    int resp;
    if(ogro >= faixas[r]) {
        resp = n-1;
        return resp;
    }
    
    
    while(l<=r){
        int meio = (l+r)/2;
        if(faixas[meio] > ogro){
            resp = meio;
            r = meio - 1; // tenta achar pos menor
        }
        else l = meio + 1;
    }

    return resp;
}

int main(){
    int n, m; // faixas e ogros
    cin >> n >> m;

    vector<int> faixas(n-1); // 3 5 
    for(int i = 0; i < (n-1); i++) cin >> faixas[i];
    // x < 3 <= y < 5 <= z     

    vector<int> premio(n);
    for(int i = 0; i < n; i++) cin >> premio[i];
    
    vector<int> forca(m);
    for(int i = 0; i < m; i++) cin >> forca[i];
    
    for(int i = 0; i < m; i++){
        int ogro = forca[i];

        int ind = lb(ogro, faixas, n);
        

        cout << premio[ind] << " ";
        //if(ind != (m-1)) cout << " ";
        // no problema ele imprime um espaco no final
    
    }

    cout << "\n";
    return 0;
}