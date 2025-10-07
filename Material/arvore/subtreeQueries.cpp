#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int in[MAXN], out[MAXN], timer;

void dfs(int u, int p) {
    in[u] = ++timer;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
    out[u] = timer;
}

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1);
    while (q--) {
        int x;
        cin >> x;
        cout << "Subtree of " << x << ": [" << in[x] << ", " << out[x] << "]\n";
    }
    return 0;
}
