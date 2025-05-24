#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n;
    vector<int> casas(n);
    for(int i = 0; i < n; i++) cin >> casas[i];
    cin >> k;

    int l = 0, r = n - 1;

    while(l < r){
        int soma = casas[l] + casas[r];

        if(soma == k){
            cout << casas[l] << " " << casas[r] << "\n";
            break;
        }
        else if(soma > k) r--; 
        else l++;
    }
    
    return 0;
}