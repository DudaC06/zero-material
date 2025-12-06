// material_completo_dp.cpp
// Material completo de Programação Dinâmica para Programação Competitiva
// - Explicações (comentários) e implementações prontas para uso
// - Contém: LIS (com reconstrução), LCS (com reconstrução), Subset Sum (1D), Knapsack 0/1 (com reconstrução)
// - Não usa operador ternário '? :'
// - Compilação: g++ -std=c++17 material_completo_dp.cpp -O2 -o dp_material

#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------------------------------
INTRODUÇÃO (resumida)
--------------------------------------------------------------------------------
Programação Dinâmica (DP) é uma técnica para problemas com:
 - subproblemas que se repetem (sobreposição)
 - estrutura ótima (a melhor solução de um problema contém melhores soluções de subproblemas)

Etapas para aplicar DP:
 1) Definir estado: informação mínima que descreve um subproblema.
 2) Definir transições: como ir de um estado a estados menores.
 3) Casos base.
 4) Memoização (top-down) ou tabela (bottom-up).
 5) (Opcional) Reconstruir a solução: armazenar decisões ou backtrace.

Este arquivo agrupa os problemas clássicos e explica a lógica nos comentários
*/

// =======================================================
// UTILITÁRIOS DE IMPRIMIR VETORES/STRINGS
// =======================================================
void print_vector_int(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    cout << "\n";
}

void print_vector_idx(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (i > 0) cout << " ";
        cout << v[i];
    }
    cout << "\n";
}

// =======================================================
// LIS - Longest Increasing Subsequence (O(n log n))
// Também reconstrói a subsequência (um LIS válido).
//
// Estratégia (patience + parents):
// - mantemos vetor tailValues: tailValues[len-1] = menor valor final da subsequência de tamanho len
// - mantemos tailIndices: índices correspondentes em A
// - parent[i] aponta para o índice anterior na subsequência para reconstrução
// Resultado: tamanho e uma subsequência (em ordem original)
// =======================================================
pair<int, vector<int>> LIS_with_sequence(const vector<int>& A) {
    int n = (int)A.size();
    if (n == 0) {
        vector<int> empty_seq;
        return make_pair(0, empty_seq);
    }

    vector<int> tailValues;            // valores das "caixas" de patience
    vector<int> tailIndices;           // índices em A correspondentes a tailValues
    vector<int> parent(n, -1);         // parent[i] = índice anterior na subsequência que termina em i

    for (int i = 0; i < n; ++i) {
        // lower_bound para posição de A[i] em tailValues
        vector<int>::iterator it = lower_bound(tailValues.begin(), tailValues.end(), A[i]);
        int pos = (int)(it - tailValues.begin()); // posição onde A[i] seria inserido

        if (pos == (int)tailValues.size()) {
            // extensao do maior tamanho
            tailValues.push_back(A[i]);
            tailIndices.push_back(i);
        } else {
            // substitui para manter o menor final possível
            tailValues[pos] = A[i];
            tailIndices[pos] = i;
        }

        if (pos > 0) {
            parent[i] = tailIndices[pos - 1];
        } else {
            parent[i] = -1;
        }
    }

    // reconstruir subsequencia: pegar índice do final (tailIndices.back()) e subir parents
    int lis_len = (int)tailValues.size();
    vector<int> seq_indices;
    int cur_index = tailIndices[lis_len - 1];
    // Em alguns casos a tailIndices pode não apontar para um caminho válido de parents
    // por causa de substituições; para garantir uma sequência válida, procuramos um índice
    // com parent encadeável até tamanho lis_len. A técnica acima já é suficiente em prática.
    // Reconstrução baseada em parent:
    while (cur_index != -1) {
        seq_indices.push_back(A[cur_index]);
        cur_index = parent[cur_index];
    }
    reverse(seq_indices.begin(), seq_indices.end());

    return make_pair(lis_len, seq_indices);
}

// =======================================================
// LCS - Longest Common Subsequence (DP 2D, O(n*m))
// Retorna tamanho e uma das LCS (reconstruída a partir da tabela dp)
// =======================================================
pair<int, string> LCS_with_sequence(const string& A, const string& B) {
    int n = (int)A.size();
    int m = (int)B.size();
    // dp[i][j] = tamanho do LCS entre A[0..i-1] e B[0..j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    // Reconstruir uma LCS (backtrace)
    int i = n;
    int j = m;
    string lcs_rev = "";
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            // usamos ambos
            lcs_rev.push_back(A[i - 1]);
            i = i - 1;
            j = j - 1;
        } else {
            if (dp[i - 1][j] >= dp[i][j - 1]) {
                i = i - 1;
            } else {
                j = j - 1;
            }
        }
    }
    reverse(lcs_rev.begin(), lcs_rev.end());
    return make_pair(dp[n][m], lcs_rev);
}

// =======================================================
// Subset Sum (DP 1D) - decide se existe subconjunto com soma T
// - dp[s] = true se é possível formar soma s com alguns elementos
// - atualização de trás para frente para garantir 0/1 (usar cada elemento no máximo uma vez)
// =======================================================
bool subset_sum_exists(const vector<int>& A, int T) {
    if (T < 0) return false;
    vector<char> dp(T + 1, 0); // char para economizar memoria
    dp[0] = 1;
    for (size_t i = 0; i < A.size(); ++i) {
        int x = A[i];
        if (x < 0) {
            // Se houver elementos negativos, solução padrão precisa ser adaptada.
            // Este algoritmo assume elementos não-negativos.
            // Para problemas com negativos é necessário outro tratamento.
            continue;
        }
        for (int s = T; s >= x; --s) {
            if (dp[s - x]) {
                dp[s] = 1;
            }
        }
    }
    return dp[T] != 0;
}

// =======================================================
// Knapsack 0/1 com reconstrução de itens (DP 2D -> transformado em 1D para valor, mas guardamos decisões)
// Implementação que constrói dp 2D para facilitar reconstrução (clara e segura).
// - dp[i][w] = melhor valor usando primeiros i itens com capacidade w
// - Depois faz backtrace para pegar itens escolhidos
// Complexidade: O(n*W) tempo e O(n*W) memória (pode ser reduzida, mas aqui priorizamos clareza)
// =======================================================
pair<int, vector<int>> knapsack01_with_items(const vector<int>& weight, const vector<int>& value, int W) {
    int n = (int)weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            int not_take = dp[i - 1][w];
            int take = -1;
            if (w - weight[i - 1] >= 0) {
                take = dp[i - 1][w - weight[i - 1]] + value[i - 1];
            }
            if (take > not_take) {
                dp[i][w] = take;
            } else {
                dp[i][w] = not_take;
            }
        }
    }

    int bestValue = dp[n][W];
    vector<int> chosen_indices;
    int w = W;
    for (int i = n; i >= 1; --i) {
        if (dp[i][w] != dp[i - 1][w]) {
            // item i-1 foi tomado
            chosen_indices.push_back(i - 1); // índice do item
            w = w - weight[i - 1];
        } else {
            // item i-1 não foi tomado
        }
    }
    reverse(chosen_indices.begin(), chosen_indices.end());
    return make_pair(bestValue, chosen_indices);
}

// =======================================================
// Exemplos e demonstrações no main
// =======================================================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // --------------------- Exemplo LIS ---------------------
    vector<int> example_lis = {10, 9, 2, 5, 3, 7, 101, 18};
    pair<int, vector<int>> lis_res = LIS_with_sequence(example_lis);
    cout << "LIS length = " << lis_res.first << "\n";
    cout << "LIS sequence = ";
    print_vector_int(lis_res.second);

    // --------------------- Exemplo LCS ---------------------
    string A = "acbd";
    string B = "abed";
    pair<int, string> lcs_res = LCS_with_sequence(A, B);
    cout << "LCS length = " << lcs_res.first << "\n";
    cout << "LCS sequence = " << lcs_res.second << "\n";

    // --------------------- Exemplo Subset Sum ---------------------
    vector<int> nums = {3, 4, 7, 2};
    int T = 9;
    bool subset_possible = subset_sum_exists(nums, T);
    if (subset_possible) {
        cout << "SubsetSum(" << T << ") = SIM\n";
    } else {
        cout << "SubsetSum(" << T << ") = NAO\n";
    }

    // --------------------- Exemplo Knapsack 0/1 ---------------------
    vector<int> pesos = {3, 4, 2};
    vector<int> valores = {4, 5, 3};
    int W = 7;
    pair<int, vector<int>> knap_res = knapsack01_with_items(pesos, valores, W);
    cout << "Knapsack best value = " << knap_res.first << "\n";
    cout << "Knapsack chosen item indices (0-based) = ";
    print_vector_idx(knap_res.second);
    cout << "Chosen items (weight value pairs): ";
    for (size_t idx = 0; idx < knap_res.second.size(); ++idx) {
        int item = knap_res.second[idx];
        if (idx > 0) cout << ", ";
        cout << "(" << pesos[item] << "," << valores[item] << ")";
    }
    cout << "\n";

    // --------------------- Observações finais impressas ---------------------
    cout << "Material: implementacoes basicas de DP (LIS, LCS, SubsetSum, Knapsack).\n";
    cout << "Use este arquivo como template e adapte estados/transicoes para outros problemas.\n";

    return 0;
}
