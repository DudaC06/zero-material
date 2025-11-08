#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        ll x; 
        cin >> n >> x;

        vector<ll> altura(n);
        ll maior_altura = 0;

        for (int i = 0; i < n; i++) {
            cin >> altura[i];
            if (altura[i] > maior_altura) {
                maior_altura = altura[i];
            }
        }

        ll esq = 1;
        ll dir = maior_altura + x;
        ll resposta = 1;

        while (esq <= dir) {
            ll meio = (esq + dir) / 2;
            ll agua_necessaria = 0;

            for (int i = 0; i < n; i++) {
                if (altura[i] < meio) {
                    agua_necessaria += (meio - altura[i]);

                    if (agua_necessaria < 0) { //overflow
                        agua_necessaria = LLONG_MAX;
                        break;
                    }
                }
            }

            if (agua_necessaria <= x) {
                resposta = meio; 
                esq = meio + 1;
            } 
            else {
                dir = meio - 1;
            }
        }

        cout << resposta << "\n";
    }

    return 0;
}
