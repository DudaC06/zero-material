// Coleção de Algoritmos Clássicos de Programação Dinâmica
// LIS (O(n log n)), LCS, Subset Sum, Knapsack 0/1
// Código limpo e pronto para uso em competições

#include <bits/stdc++.h>
using namespace std;

/* =====================================================
   LIS — Longest Increasing Subsequence (O(n log n))
   Retorna o tamanho do LIS
   ===================================================== */
int LIS(vector<int>& a){
    vector<int> tails;
    for(int x: a){
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if(it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return (int)tails.size();
}

/* =====================================================
   LCS — Longest Common Subsequence (O(n*m))
   Retorna o tamanho do LCS
   ===================================================== */
int LCS(const string& A, const string& B){
    int n=A.size(), m=B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

/* =====================================================
   SUBSET SUM — Decide se existe subconjunto com soma T
   DP 1D (O(n*T))
   ===================================================== */
bool subsetSum(vector<int>& a, int T){
    vector<int> dp(T+1, 0);
    dp[0] = 1; // somar 0 sempre é possível

    for(int x : a){
        for(int s=T; s>=x; s--){
            if(dp[s-x]) dp[s] = 1;
        }
    }
    return dp[T];
}

/* =====================================================
   KNAPSACK 0/1 — Melhor valor com capacidade W
   DP 1D (O(n*W))
   ===================================================== */
int knapsack01(vector<int>& w, vector<int>& v, int W){
    vector<int> dp(W+1, 0);
    int n = w.size();

    for(int i=0;i<n;i++){
        for(int cap=W; cap>=w[i]; cap--){
            dp[cap] = max(dp[cap], dp[cap - w[i]] + v[i]);
        }
    }
    return dp[W];
}

/* =====================================================
   Main com exemplos simples de execução
   ===================================================== */
int main(){
    // -------------------- LIS --------------------
    vector<int> arr = {10,9,2,5,3,7,101,18};
    cout << "LIS = " << LIS(arr) << "\n";

    // -------------------- LCS --------------------
    string A = "acbd", B = "abed";
    cout << "LCS = " << LCS(A,B) << "\n";

    // -------------------- Subset Sum --------------------
    vector<int> nums = {3,4,7,2};
    int T = 9;
    if(subsetSum(nums, T)){
        cout << "SubsetSum(9) = SIM" << "\\n";
    } else {
        cout << "SubsetSum(9) = NAO" << "\\n";
    }

    // -------------------- Knapsack 0/1 --------------------(9) = " << (subsetSum(nums,T) ? "SIM" : "NAO") << "\n";

    // -------------------- Knapsack 0/1 --------------------
    vector<int> peso = {3,4,2};
    vector<int> valor = {4,5,3};
    int W = 7;
    cout << "Knapsack = " << knapsack01(peso,valor,W) << "\\n"; " << knapsack01(peso,valor,W) << "\n";

    return 0;
}
