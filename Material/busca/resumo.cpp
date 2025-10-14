#include <bits/stdc++.h>
using namespace std;

/*

- Problemas exaustivos (ou brute force): testam todas as combinações possíveis.
- Busca (search): explora estados de forma sistemática até encontrar uma solução.

Técnicas principais:
1. Enumeração simples  → testar todos os casos (for, recursão)
2. Backtracking         → explorar e "voltar" quando o caminho não serve
3. Branch and Bound     → poda caminhos ruins (usa heurísticas)
4. DFS / BFS            → busca em profundidade e largura (em grafos)
Em maratonas:
- Saber gerar subconjuntos, permutações e combinações é essencial.
- Sempre analisar complexidade (ex: 2^n, n!, etc.).
- Usar recursão com cuidado (stack e tempo).

- Vetores (vector<int>) → lista dinâmica
- Funções recursivas    → chamam a si mesmas
- Passagem por referência (&) → evita cópia e melhora desempenho
- Backtracking usa: if, for, chamadas recursivas, pop_back()
- Complexidade: medir o número de chamadas / estados
*/

// GERAÇÃO DE SUBCONJUNTOS (Power Set)
void gerarSubconjuntos(vector<int> &nums, int i, vector<int> &atual) {
    if (i == (int)nums.size()) {
        cout << "{ ";
        for (int x : atual) cout << x << " ";
        cout << "}\n";
        return;
    }
    // Escolher não incluir nums[i]
    gerarSubconjuntos(nums, i + 1, atual);

    // Escolher incluir nums[i]
    atual.push_back(nums[i]);
    gerarSubconjuntos(nums, i + 1, atual);
    atual.pop_back(); // backtrack
}

//  GERAÇÃO DE PERMUTAÇÕES
void gerarPermutacoes(vector<int> &nums, int i) {
    if (i == (int)nums.size()) {
        for (int x : nums) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int j = i; j < (int)nums.size(); j++) {
        swap(nums[i], nums[j]);           // escolhe elemento
        gerarPermutacoes(nums, i + 1);    // recursão
        swap(nums[i], nums[j]);           // desfaz (backtrack)
    }
}

//SUBSET SUM (Existe subconjunto com soma == alvo?)

bool subsetSum(vector<int> &nums, int i, int soma, int alvo) {
    if (i == (int)nums.size()) return soma == alvo;
    // não pega
    if (subsetSum(nums, i + 1, soma, alvo)) return true;
    // pega
    if (subsetSum(nums, i + 1, soma + nums[i], alvo)) return true;
    return false;
}


// 4️ PROBLEMA DAS N-QUEENS (Rainhas no tabuleiro)
bool podeColocar(vector<int> &coluna, int linha, int c) {
    for (int i = 0; i < linha; i++) {
        int c2 = coluna[i];
        if (c2 == c || abs(c - c2) == abs(linha - i))
            return false;
    }
    return true;
}

void nQueens(int n, int linha, vector<int> &coluna) {
    if (linha == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << (coluna[i] == j ? "Q " : ". ");
            cout << "\n";
        }
        cout << "-------------------\n";
        return;
    }

    for (int c = 0; c < n; c++) {
        if (podeColocar(coluna, linha, c)) {
            coluna[linha] = c;
            nQueens(n, linha + 1, coluna);
            coluna[linha] = -1; // backtrack
        }
    }
}

// BUSCA EM LABIRINTO (DFS Recursivo)
int n, m;
vector<vector<int>> lab;
vector<vector<int>> visitado;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool dfsLab(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    if (lab[x][y] == 1 || visitado[x][y]) return false;
    if (x == n - 1 && y == m - 1) return true;

    visitado[x][y] = 1;
    for (int d = 0; d < 4; d++) {
        if (dfsLab(x + dx[d], y + dy[d]))
            return true;
    }
    return false;
}



int main() {
    cout << "===== SUBCONJUNTOS =====\n";
    vector<int> nums = {1, 2, 3};
    vector<int> atual;
    gerarSubconjuntos(nums, 0, atual);

    cout << "\n===== PERMUTACOES =====\n";
    gerarPermutacoes(nums, 0);

    cout << "\n===== SUBSET SUM (alvo=5) =====\n";
    cout << (subsetSum(nums, 0, 0, 5) ? "Existe\n" : "Nao existe\n");

    cout << "\n===== N-QUEENS (n=4) =====\n";
    int n = 4;
    vector<int> coluna(n, -1);
    nQueens(n, 0, coluna);

    cout << "\n===== LABIRINTO =====\n";
    lab = {
        {0, 0, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 1, 0}
    };
    n = 4, m = 4;
    visitado.assign(n, vector<int>(m, 0));
    cout << (dfsLab(0, 0) ? "Caminho encontrado\n" : "Sem caminho\n");

    return 0;
}
