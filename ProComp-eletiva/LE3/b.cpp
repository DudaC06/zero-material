#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> pai, tamanho;
    int componentes, maior_componente;

    DSU(int n) : pai(n + 1), tamanho(n + 1, 1), componentes(n), maior_componente(1) {
        iota(pai.begin(), pai.end(), 0);
    }

    int encontrar(int x) {
        while (x != pai[x]) {
            pai[x] = pai[pai[x]];
            x = pai[x];
        }
        return x;
    }

    void unir(int a, int b) {
        int raiz_a = encontrar(a);
        int raiz_b = encontrar(b);

        if (raiz_a == raiz_b) return;

        if (tamanho[raiz_a] < tamanho[raiz_b]) {
            swap(raiz_a, raiz_b);
        }

        pai[raiz_b] = raiz_a;
        tamanho[raiz_a] += tamanho[raiz_b];

        componentes--;
        maior_componente = max(maior_componente, tamanho[raiz_a]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    DSU dsu(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        dsu.unir(u, v);
        cout << dsu.componentes << " " << dsu.maior_componente << '\n';
    }

    return 0;
}
