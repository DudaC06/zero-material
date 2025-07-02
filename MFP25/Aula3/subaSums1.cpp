#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n;
    ll x; // soma alvo
    cin >> n >> x;
    
    vector<int> array(n); // preenche array
    for(int i = 0; i < n; i++) cin >> array[i];

    // quantas subarrays (segmentos contíguos do vetor) têm soma exata igual a x
    
    // a chave (ll) representa a soma prefixada e o valor (int) quantas vezes ela apareceu
    unordered_map<ll, int> cont;
    cont[0] = 1;

    ll soma = 0, resp = 0;
    for(int i = 0; i < n; i++){
        soma += array[i]; // soma acumulada até o índice i

        // se eu tenho um valor resultante da subtracao da soma por x, é pq tem um subarray que a soma da x
        resp += cont[soma - x];

        cont[soma]++;  // registra a soma atual
    }

    cout << resp << "\n"; 

    return 0;
}