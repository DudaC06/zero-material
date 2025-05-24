#include<bits/stdc++.h>
using namespace std;

#define ll long long

void somaDois(vector<pair<ll, ll>>& v, ll n, ll x){
    // primeira e ultima posicao 
    ll l = 0, r = n - 1; 

    while(l < r){
        ll soma = v[l].first + v[r].first;

        if(soma == x){
            //imprime as posicoes
            cout << v[l].second << " " << v[r].second << "\n";
            return;
        }
        else if(soma > x) r--; // diminui numeros
        else l++; // aumenta numeros
    }

    cout << "IMPOSSIBLE\n";
}

int main(){
    ll n, x;
    cin >> n >> x;

    vector<pair<ll, ll>> array;
    // vetor valor, poiscao
    for(int i = 0; i < n; i++){
        ll z;
        cin >> z;
        array.push_back({z, i+1});
    }
    // ordena se baseando no primeiro valor do par
    sort(array.begin(), array.end());

    somaDois(array, n, x);

    return 0;
}