#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 18; // Para n até 2 * 10^5, log2(200000) ≈ 17.6

vector<int> adj[MAXN];
int up[MAXN][LOG], depth[MAXN];

// DFS para calcular profundidade e ancestrais
void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < LOG; ++i) {
        if (up[u][i - 1] != -1) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
    }
    for (int v : adj[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

// Função para encontrar o LCA de u e v
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    // Eleva u até a mesma profundidade de v
    for (int i = LOG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = up[u][i];
        }
    }
    if (u == v) return u;
    // Eleva ambos até o LCA
    for (int i = LOG - 1; i >= 0; --i) {
        if (up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        fill(up[i], up[i] + LOG, -1);
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << endl;
    }
    return 0;
}
