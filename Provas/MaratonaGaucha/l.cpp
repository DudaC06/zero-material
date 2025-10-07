#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> tribos(n);

    for (int i = 0; i < n; ++i) {
        cin >> tribos[i];
    }

    int abc = 0; // variável exigida

    // Verifica se há apenas uma tribo dominante
    int maior = *max_element(tribos.begin(), tribos.end());
    int count_maior = count(tribos.begin(), tribos.end(), maior);

    if (count_maior == 1) {
        // Há uma única tribo dominante
        abc = maior;
        cout << abc << "\n";
        return 0;
    }

    int menor_alianca = INT_MAX;

    // Testa todas as combinações de pares de tribos
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int alianca = tribos[i] + tribos[j];
            bool eh_dominante = true;

            for (int k = 0; k < n; ++k) {
                if (k != i && k != j && tribos[k] >= alianca) {
                    eh_dominante = false;
                    break;
                }
            }

            if (eh_dominante) {
                menor_alianca = min(menor_alianca, alianca);
            }
        }
    }

    if (menor_alianca == INT_MAX) {
        cout << -1 << "\n";
    } else {
        abc = menor_alianca;
        cout << abc << "\n";
    }

    return 0;
}
