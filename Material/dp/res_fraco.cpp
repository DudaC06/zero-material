// Resumo unificado de Programação Dinâmica - DP1
// Arquivo gerado como explicação condensada do slide
// Autor: ChatGPT

#include <bits/stdc++.h>
using namespace std;

/*
============================
  RESUMO GERAL – PROGRAMACAO DINAMICA
============================
DP = Backtracking + Memoizacao
DP é usada quando um problema tem:
  • Subproblemas que se repetem
  • Solução depende de escolhas (transições)
  • Estados bem definidos

Estrutura geral:
    estado -> menor conjunto de info que define o subproblema
    transicao -> escolha que leva de um estado ao outro
    memo/DP -> salva resultados intermediários

============================
  EXEMPLO DO SLIDE: Maior soma subsequência com |A[i] - A[j]| <= K
============================
Estado: (i, X)
  i = posição atual
  X = último valor usado na subsequência

Transições:
  • Não pegar A[i]  -> (i+1, X)
  • Pegar A[i]      -> (i+1, A[i]) se |A[i] - X| <= K

Memoização evita recomputação dos mesmos estados.

============================
  LIS – Longest Increasing Subsequence
============================
Definição: maior subsequência estritamente crescente.

DP clássica O(n^2):
    dp[i] = maior LIS terminando em i
    dp[i] = 1 + max(dp[j]) para todo j < i e A[j] < A[i]

Versão otimizada: O(n log n) usando vetor "tails".

============================
  LCS – Longest Common Subsequence
============================
Entre duas strings A e B:

DP 2D:
  dp[i][j] = LCS de A[0..i] e B[0..j]

  se A[i] == B[j]:
      dp[i][j] = dp[i-1][j-1] + 1
  senão:
      dp[i][j] = max(dp[i-1][j], dp[i][j-1])

Complexidade: O(n*m)

============================
  SUBSET SUM
============================
Pergunta: existe subconjunto com soma T?

DP 2D:
  dp[i][s] = dá para formar soma s com primeiros i elementos?

DP 1D:
  dp[s] = possível formar s?

Complexidade: O(n*T)

============================
  KNAPSACK 0/1
============================
Capacidade W, itens com peso e valor.

DP 2D:
  dp[i][w] = melhor valor usando itens até i com capacidade w

DP 1D:
  dp[w] = melhor valor com capacidade w (processa pesos de trás para frente)

Complexidade: O(n*W)

============================
  RECONSTRUÇÃO DA RESPOSTA
============================
Para recuperar caminho/itens:
  • Criar tabela rec[][] guardando de onde veio dp[i][j]
  • Andar do fim até o início seguindo rec
  • Inverter caminho

============================
Código-exemplo simples apenas para mostrar estrutura de memoização:
============================
*/

const int MAXN = 100005;
vector<int> A;
int N, K;
map<pair<int,int>, long long> memo;

long long maior_soma(int i, int X) {
    if (i >= N) return 0;

    auto key = make_pair(i, X);
    if (memo.count(key)) return memo[key];

    long long ans = maior_soma(i+1, X); // não pega A[i]

    if (abs(A[i] - X) <= K) {
        ans = max(ans, maior_soma(i+1, A[i]) + A[i]);
    }

    return memo[key] = ans;
}

int main(){
    // Exemplo de uso do código
    // (apenas ilustrativo, não é o foco do resumo)
    A = {8,10,6,4,2,4};
    N = A.size();
    K = 2;

    long long resposta = 0;
    for(int i=0;i<N;i++){
        resposta = max(resposta, maior_soma(i+1, A[i]) + A[i]);
    }

    cout << "Maior soma válida = " << resposta << "\n";
    return 0;
}
