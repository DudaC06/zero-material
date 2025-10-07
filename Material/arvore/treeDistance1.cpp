#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int dist[200005], size[200005], total_dist[200005];

void dfs1(int u, int p) {
    size[u] = 1;
    dist[u] = 0;
    for (int v : adj[u]) {
        if (v != p) {
            dfs1(v, u);
            size[u] += size[v];
            dist[u] += dist[v] + size[v];
        }
    }
}

void dfs2(int u, int p) {
    total_dist[u] = dist[u];
    for (int v : adj[u]) {
        if (v != p) {
            dist[v] = dist[u] - size[v] + (total_dist[u] - dist[v]);
            dfs2(v, u);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}
