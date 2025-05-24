#include<bits/stdc++.h>
using namespace std;

int main (){
    string s;
    cin >> s;  

    int n = s.size() / 2;  

    string a = "";
    string b = "";

    for (int i = 0; i < n; i++) {
        a += s[2 * i];     //  posicao par
        b += s[2 * i + 1]; // posicao impar
    }

    cout << a << "\n";
    cout << b << "\n";
    return 0;
}