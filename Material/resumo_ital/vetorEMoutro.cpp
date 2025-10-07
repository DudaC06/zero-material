#include <bits/stdc++.h>
using namespace std;

int main() {
    // Vetores de exemplo
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> B = {3, 4};
    vector<int> C = {4, 3};        // mesma quantidade, mas ordem diferente
    vector<int> D = {3, 3, 4};     // com repetições

    // ===============================
    // 1. Verificar SUBVETOR CONTÍNUO
    // ===============================
    // Verifica se B aparece como sequência contínua dentro de A
    auto it = search(A.begin(), A.end(), B.begin(), B.end());
    if (it != A.end()) {
        cout << "1. B é subvetor contínuo de A ✅" << endl;
    } else {
        cout << "1. B NÃO é subvetor contínuo de A ❌" << endl;
    }

    // ===================================================
    // 2. Verificar se todos os ELEMENTOS de B estão em A
    // (ordem não importa e sem repetição necessária)
    // ===================================================
    unordered_set<int> conjuntoA(A.begin(), A.end());

    bool todos_presentes = all_of(B.begin(), B.end(), [&](int x) {
        return conjuntoA.count(x); // retorna true se x estiver presente
    });

    if (todos_presentes) {
        cout << "2. Todos os elementos de B estão em A ✅" << endl;
    } else {
        cout << "2. Nem todos os elementos de B estão em A ❌" << endl;
    }

    // =========================================================
    // 3. Verificar se todos os ELEMENTOS de D estão em A
    // com suas QUANTIDADES (como multiconjunto, tipo bag)
    // =========================================================
    map<int, int> freqA, freqD;
    for (int x : A) freqA[x]++;
    for (int x : D) freqD[x]++;

    bool contido_com_frequencia = true;
    for (auto [val, qtd] : freqD) {
        if (freqA[val] < qtd) {
            contido_com_frequencia = false;
            break;
        }
    }

    if (contido_com_frequencia) {
        cout << "3. D está contido em A com frequência correta ✅" << endl;
    } else {
        cout << "3. D NÃO está contido em A com a frequência correta ❌" << endl;
    }

    return 0;
}
