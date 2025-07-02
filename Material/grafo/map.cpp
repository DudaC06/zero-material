#include <bits/stdc++.h>
using namespace std;

int main() {

    // --- O que é um map ---
    // map<chave, valor> - armazena pares (chave, valor) com chave única e ordenada

    map<string, int> idade;

    // --- Inserção e acesso ---
    idade["Ana"] = 20;              // insere ou atualiza
    idade["Bruno"] = 22;

    idade.insert({"Carlos", 25});   // insere (se não existir)

    cout << idade["Ana"] << "\n";   // acesso por chave (20)
    // cout << idade.at("Joao");    // .at() lança exceção se não existir

    // --- Verificar existência ---
    if (idade.count("Bruno")) {
        cout << "Bruno está no map\n";
    }

    if (idade.find("Carlos") != idade.end()) {
        cout << "Carlos está no map\n";
    }

    // --- Remover ---
    idade.erase("Ana"); // remove a chave "Ana" (se existir)

    // --- Iterar ---
    for (auto& par : idade) {
        cout << par.first << " -> " << par.second << "\n";
    }

    // Outra forma: destrinchar o par usando structured bindings (C++17+)
    for (auto [nome, idade_pessoa] : idade) {
        cout << nome << " tem " << idade_pessoa << " anos\n";
    }

    // --- Exemplo prático: contar frequências ---
    int n, x;
    cin >> n;
    map<int, int> freq;
    while (n--) {
        cin >> x;
        freq[x]++;
    }

    for (auto& par : freq) {
        cout << par.first << " aparece " << par.second << " vezes\n";
    }

    // --- Dicas ---
    // map: mantém ordenado, operações em O(log N)
    // unordered_map: mais rápido, mas sem ordem (usa hash)
    // tipos possíveis de chave: int, string, pair, etc

    // Exemplo de map com par como chave:
    map<pair<int, int>, int> arestas;
    arestas[{1, 2}] = 10;

    cout << "Peso da aresta (1, 2): " << arestas[{1, 2}] << "\n";

    return 0;
}
