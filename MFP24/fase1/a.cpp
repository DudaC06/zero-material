#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool check(vector<ll> v, ll n, ll p, ll tempo){
    ll soma = 0;
    for(ll s : v){ // s são os elementos do vetor
        soma += tempo/s; //qnts pizzas cada um leva por segundo
        if(soma >= p) return true;
    }

    return false;
}

ll bb_resp(vector<ll> v, ll n, ll p){
    ll resposta = -1;

    // busca entre todas as possiveis respostas
    // pior caso 1 jogador pra levar 10⁹ pizzas e demora 10⁹ segundos, 10¹⁸
    ll l = 0, r = 1000000000000000000;

    while(l < r){ // enquanto os ponteiro não se ultrapassrem
        ll meio = (l+r) / 2;
        if(check(v, n, p, meio)){ // da certo
            resposta = meio;
            r = meio - 1; // tenta achar um menor
        }
        else{
            l = meio + 1; // muito pequeno
        }
    }

    return resposta;
}


int main(){
    
    // força A, demora A segundos para carregar uma pizza

    ll n, p; // competidores e pizzas
    cin >> n >> p;

    vector<ll> forca(n);
    for(int i = 0; i < n; i++) cin >> forca[i];

    // tempo minimo
    
    ll resp = bb_resp(forca, n, p);

    cout << resp << "\n";
    
    return 0;
}