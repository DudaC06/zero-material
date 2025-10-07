#include<bits/stdc++.h>
using namespace std;

#define ll long long 
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    string s;
    cin >> s;
    
    vector<int> valor(26);
    int cont = 0; 
    for(int i = 26; i >= 1; i--){
        valor[cont] = i;
        cont++;
    } 

    ll senha = 0;

    for(char c : s){
        senha += valor[c - 97];
    }

    cout << senha << "\n";

    return 0;
}

