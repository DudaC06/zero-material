// ==========================================
// AULA 2 - BUSCAS E BACKTRACKING
// ==========================================
#include <bits/stdc++.h>
using namespace std;

// -----------------------------------------------------
// BUSCA LINEAR
// Percorre todo o vetor procurando um valor.
// Complexidade: O(N)
// -----------------------------------------------------
bool buscaLinear(const vector<int>& v, int x) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] == x) return true;
    }
    return false;
}

// -----------------------------------------------------
// BUSCA BINÁRIA (MANUAL)
// Requer vetor ORDENADO!
// Divide o espaço de busca pela metade a cada passo.
// Complexidade: O(log N)
// -----------------------------------------------------
bool buscaBinaria(const vector<int>& v, int x) {
    int l = 0, r = v.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == x) return true;
        else if (v[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

// -----------------------------------------------------
// FUNÇÕES BINÁRIAS DA STL
// binary_search, lower_bound e upper_bound
// -----------------------------------------------------
void stl_binary_functions_demo() {
    vector<int> v = {1, 2, 3, 3, 3, 4, 5};
    sort(v.begin(), v.end());

    bool existe = binary_search(v.begin(), v.end(), 3); // true
    auto it1 = lower_bound(v.begin(), v.end(), 3); // primeiro >= 3
    auto it2 = upper_bound(v.begin(), v.end(), 3); // primeiro > 3

    cout << "3 existe? " << existe << "\n";
    cout << "Lower bound de 3 -> índice " << (it1 - v.begin()) << "\n";
    cout << "Upper bound de 3 -> índice " << (it2 - v.begin()) << "\n";
}

// -----------------------------------------------------
// BUSCA BINÁRIA NA RESPOSTA (Monotonic Function Search)
// Usada em problemas onde f(x) é MONÓTONA (ex: cresce sempre)
// Exemplo: menor tempo t tal que f(t) >= alvo
// -----------------------------------------------------
bool f(long long x) {
    // Exemplo: "x máquinas produzem >= 100 itens em 10s?"
    return x * 2 >= 100; // função qualquer apenas para ilustrar
}

long long buscaResposta(long long l, long long r) {
    while (l < r) {
        long long mid = (l + r) / 2;
        if (f(mid)) r = mid; // queremos o menor x que satisfaça f(x)
        else l = mid + 1;
    }
    return l;
}

// -----------------------------------------------------
// TWO POINTERS (Dois ponteiros)
// Encontra o maior subarray com soma <= S.
// Complexidade: O(N)
// -----------------------------------------------------
int twoPointers(vector<int>& v, int S) {
    int n = v.size();
    int l = 0, sum = 0, ans = 0;
    for (int r = 0; r < n; r++) {
        sum += v[r];
        // enquanto soma ultrapassar o limite, move o ponteiro esquerdo
        while (sum > S) {
            sum -= v[l];
            l++;
        }
        ans = max(ans, r - l + 1); // tamanho do segmento válido
    }
    return ans;
}

// -----------------------------------------------------
// SWEEP LINE + PREFIX SUM
// Conta quantos intervalos contêm um ponto dado.
// Complexidade: O(N + Q + M) (linear no tamanho do vetor)
// -----------------------------------------------------
void sweepLineExample() {
    int N = 3;
    vector<pair<int,int>> intervalos = {{1,5}, {3,7}, {4,10}};
    int MAXN = 11; // limite superior + 1
    vector<int> v(MAXN, 0);

    // marca entradas e saídas dos intervalos
    for (auto [l, r] : intervalos) {
        v[l]++;   // entra intervalo
        v[r]--;   // sai intervalo
    }

    // prefix sum para contar quantos intervalos ativos em cada ponto
    for (int i = 1; i < MAXN; i++)
        v[i] += v[i - 1];

    // exemplo de queries
    vector<int> queries = {6, 2, 4};
    for (int q : queries)
        cout << "Ponto " << q << " está em " << v[q] << " intervalos.\n";
}

// -----------------------------------------------------
// BUSCA EXAUSTIVA (Complete Search)
// Gera todas as combinações possíveis e testa cada uma.
// Usada quando N é pequeno (N <= 20).
// -----------------------------------------------------
void gerarSubconjuntos(vector<int>& v) {
    int n = v.size();
    for (int mask = 0; mask < (1 << n); mask++) {
        cout << "{ ";
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) cout << v[i] << " ";
        }
        cout << "}\n";
    }
}

// -----------------------------------------------------
// BACKTRACKING - exemplo: gerar permutações de N elementos
// -----------------------------------------------------
vector<int> atual;
vector<bool> usado;

void permutacoes(int n) {
    if ((int)atual.size() == n) {
        for (int x : atual) cout << x << " ";
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!usado[i]) {
            usado[i] = true;      // faz
            atual.push_back(i);
            permutacoes(n);       // recursão
            atual.pop_back();     // desfaz
            usado[i] = false;
        }
    }
}

// -----------------------------------------------------
// BACKTRACKING COM PODA - Exemplo: Subset Sum
// -----------------------------------------------------
int target = 10;
vector<int> nums = {2, 3, 5, 7};

void subsetSum(int idx, int soma) {
    if (soma > target) return; // poda: soma já passou do limite
    if (idx == (int)nums.size()) {
        if (soma == target)
            cout << "Soma encontrada!\n";
        return;
    }
    // inclui o elemento atual
    subsetSum(idx + 1, soma + nums[idx]);
    // não inclui o elemento atual
    subsetSum(idx + 1, soma);
}

// -----------------------------------------------------
// MAIN DEMO
// -----------------------------------------------------
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> v = {2, 6, 4, 3, 6, 8, 9};
    cout << "Maior subarray com soma <= 20: " << twoPointers(v, 20) << "\n\n";

    sweepLineExample();

    cout << "\nPermutações de 3 elementos:\n";
    usado.assign(4, false);
    permutacoes(3);

    cout << "\nSubconjuntos com soma = 10:\n";
    subsetSum(0, 0);

    return 0;
}
