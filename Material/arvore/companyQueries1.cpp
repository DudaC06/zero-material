#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXK = 18;
int up[MAXN][MAXK], depth[MAXN];

void dfs(int u, int p) {
    up[u][0] = p;
    for (int i = 1; i < MAXK; ++i) {
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

int get_kth_ancestor(int u, int k) {
    for (int i = 0; i < MAXK; ++i) {
        if (k & (1 << i)) {
            u = up[u][i];
        }
    }
    return u;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        fill(up[i], up[i] + MAXK, -1);
    }
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    for (int i = 0; i < q; ++i) {
        int x, k;
        cin >> x >> k;
        cout << get_kth_ancestor(x, k) << endl;
    }
    return 0;
}
