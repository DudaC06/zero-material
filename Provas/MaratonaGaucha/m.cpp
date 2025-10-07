#include<bits/stdc++.h>
using namespace std;

bool palindromo(const string& p){

    int l = 0, r = p.size() - 1;
    while (l < r) {
        if (p[l] != p[r]) return false;
        l++;
        r--;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    string s;
    cin >> s;

    // verifica se eh
    if(palindromo(s)) cout << "0\n";

    else{ // adiciona letras
        int n = s.size();

        set<char> letras;
        for (char c : s) letras.insert(c);
        int tam_dif = letras.size();

        if(tam_dif == n){
            cout << n-1 << "\n"; //n pali
        }


        for (int i = 0; i < tam_dif; i++) {
            string teste = s; //reinicia
            string sub = s.substr(0,i);
            reverse(sub.begin(), sub.end());
            teste += sub;

        if (palindromo(teste)) {
            cout << i << '\n';
            return 0;
        }
    }
    }

    return 0;
}

