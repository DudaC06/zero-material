#include <bits/stdc++.h>  
using namespace std;

int gcd(int a, int b) { //funcao mdc
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a; 
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> saltos(n);
    for (int i = 0; i < n; i++) {
        cin >> saltos[i];
    }

    int mdc = saltos[0];
    for(int i = 1; i < n; i++) {
        mdc = gcd(mdc, saltos[i]);
    }

    if (abs(x) % mdc == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
