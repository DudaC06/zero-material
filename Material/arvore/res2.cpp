#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int n, q;
vector<int> adj[MAXN];

// Arrays para Euler Tour
int tin[MAXN], tout[MAXN], timer = 0;
int val[MAXN];       // Valor de cada nó
int flat[2*MAXN];   // Array linearizado da árvore

// Segment Tree
int t[4*MAXN];

// Euler Tour + DFS
void dfs(int u, int p) {
    tin[u] = timer;
    flat[timer++] = val[u];
    for (int v : adj[u]) {
        if (v != p) dfs(v, u);
    }
    tout[u] = timer - 1; // último índice da subárvore
}

// Segment Tree
void build(int node, int l, int r) {
    if (l == r) {
        t[node] = flat[l];
    } else {
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        t[node] = t[2*node] + t[2*node+1];
    }
}

void update(int node, int l, int r, int idx, int value) {
    if (l == r) {
        t[node] = value;
    } else {
        int mid = (l + r)/2;
        if (idx <= mid) update(2*node, l, mid, idx, value);
        else update(2*node+1, mid+1, r, idx, value);
        t[node] = t[2*node] + t[2*node+1];
    }
}

int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) return t[node];
    int mid = (l + r)/2;
    return query(2*node, l, mid, ql, qr) + query(2*node+1, mid+1, r, ql, qr);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    // Leitura dos valores dos nós
    for (int i = 1; i <= n; i++) cin >> val[i];

    // Leitura da árvore
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS para calcular Euler Tour
    dfs(1, -1);

    // Construção da Segment Tree
    build(1, 0, n-1);

    // Processamento das queries
    while(q--) {
        int type;
        cin >> type;
        if(type == 1) {
            // Update: alterar valor do nó x para y
            int x, y;
            cin >> x >> y;
            update(1, 0, n-1, tin[x], y);
        } else {
            // Query: soma dos valores na subárvore do nó x
            int x;
            cin >> x;
            cout << query(1, 0, n-1, tin[x], tout[x]) << "\n";
        }
    }

    return 0;
}
