#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll troca(vector<int>& vetor, int inicio, int fim) {
    if (fim - inicio <= 1) return 0;

    int meio = (inicio + fim) / 2;
    ll total = troca(vetor, inicio, meio) + troca(vetor, meio, fim);
    vector<int> intercalado;
    int i = inicio, j = meio;

    while (i < meio && j < fim) {
        if (vetor[i] <= vetor[j]) {
            intercalado.push_back(vetor[i++]);
        } else {
            total += meio - i;
            intercalado.push_back(vetor[j++]);
        }
    }

    while (i < meio) intercalado.push_back(vetor[i++]);
    while (j < fim) intercalado.push_back(vetor[j++]);

    copy(intercalado.begin(), intercalado.end(), vetor.begin() + inicio);

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testes;
    cin >> testes;

    while (testes--) {
        int qtd;
        cin >> qtd;

        vector<pair<int, int>> pessoas(qtd);
        for (int i = 0; i < qtd; ++i) {
            cin >> pessoas[i].first >> pessoas[i].second;
        }

        sort(pessoas.begin(), pessoas.end());
        vector<int> finais;
        for (const auto& p : pessoas) {
            finais.push_back(p.second);
    }
        cout << troca(finais, 0, qtd) << '\n';
    }

    return 0;
}
