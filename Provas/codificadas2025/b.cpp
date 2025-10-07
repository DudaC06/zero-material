#include<bits/stdc++.h>
using namespace std;

int contar(const string& str, char letra) {
    // primeira e ultima posicao com lb e up
    auto primeiro = lower_bound(str.begin(), str.end(), letra);
    auto ultimo = upper_bound(str.begin(), str.end(), letra);
    
    return ultimo - primeiro;
}


int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    //letras T C S
    string p;
    cin >> p;
    
    sort(p.begin(), p.end());

    int t = contar(p,'T');
    int c = contar(p,'C');
    int s = contar(p,'S');

    if((t == c) && (c == s)) cout << "YES\n";
    else cout << "NO\n";
    //cout << t << c << s;
    
    return 0;
}