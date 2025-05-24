#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    vector<int> v = {1, 2, 3, 4, 4, 7, 8, 8};
    
    int x = 4;
    int inicio = 0, final = n - 1;
    
    int resposta = -1; // representa que não encontrou
    
    while (inicio <= final) {
        int meio = (inicio + final) / 2;
        if (v[meio] > x) {
            resposta = meio;
            final = meio - 1; // tenta buscar posição menor que ainda satisfaça
        } else {
            inicio = meio + 1;
        }
    }
    
    cout << resposta << "\n"; // lembrando: retorna o índice
    return 0;
    
}

