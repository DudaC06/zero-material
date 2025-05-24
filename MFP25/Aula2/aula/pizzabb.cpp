#include<bits/stdc++.h>
using namespace std;

#define ll long long

// verifica se o segundos pega
bool check(ll meio,int n, int p, vector<int> t){
    ll soma = 0;
    for(int i = 0; i < n; i++){
        soma+= meio/t[i]; //qnts pizzas cada um pd pegar
    }

    if(soma >= p) return true;
    else return false;
}


// vamos chutas o intervalo da resposta
ll bb(int n, int p, vector<int> t){
    ll resposta = -1;

    //o pior caso 10^18 pois pode ter uma pessoa que carrega 10^9 pizzas em 10^9 segundos
    ll l = 1, r = 1000000000000000000;

    while(l <= r){ //roda enquanto os 'ponteiros' n se cruzarem
        ll meio = (l+r) / 2;

        if(check(meio, n, p, t)){ //verifica se e o min funciona
            resposta = meio;
            r = meio - 1; //tenta achar um menor, descarta a direito
        }
        else{
            l = meio + 1; // tem q ser maior, descarta a esquerda
        }
    }

    return resposta;
}

int main(){
    int n, p;
    cin >> n >> p;

    vector<int> tempo(n);
    for(int i = 0; i < n; i++) cin >> tempo[i];
    
    ll seg = bb(n, p, tempo);

    cout << seg << "\n";
    return 0;
}