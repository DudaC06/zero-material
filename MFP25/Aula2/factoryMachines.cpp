#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool check(vector<ll>& tempo, ll n, ll t, ll meio){

    ll soma = 0;

    for(int i = 0; i < n; i++){
        soma += meio/tempo[i];
        if(soma>=t) return true;
    }

    return false;

}

ll bb(vector<ll>& tempo, ll n, ll t){
    ll l = 1, r = 1e18; 
    ll resp = -1;
    
    while(l <= r){
        ll meio = l + (r - l)/2;

        if(check(tempo, n, t, meio)){ //se for valido
            resp = meio;
            r = meio - 1; //tenta achar um menor
        }
        else l = meio + 1;
    }

    return resp;
}

int main(){
    ll n;
    ll t;
    cin >> n >> t;

    vector<ll> tempo(n);
    for(int i = 0; i < n; i++) cin >> tempo[i];

    //chutar a resposta com bb
    ll segundos = bb(tempo, n , t);

    cout << segundos << "\n";
    return 0;
}