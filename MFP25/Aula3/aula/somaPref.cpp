#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; //tamanho do array

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    //  vetor de soma prefixada
    vector<int> prefix(n);
    prefix[0] = a[0]; // dica:indexe o vetor de soma de prefixo em 1
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    // mostra soma prefixada
    cout << "Vetor de soma prefixada:\n";
    for (int i = 0; i < n; i++) {
        cout << prefix[i] << " ";
    }
    cout << "\n";

    // Exemplo de uso: soma do intervalo [l, r]
    int l, r;
    cout << "Digite os índices l e r (0-based) para somar o intervalo [l, r]: ";
    cin >> l >> r;

    int soma = prefix[r];
    if (l > 0) soma -= prefix[l - 1];
    
    cout << "Soma do intervalo [" << l << ", " << r << "] = " << soma << "\n";

    return 0;
}
