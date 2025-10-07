#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int dist[200005], farthest_node;

void dfs(int u, int p, int d) {
    dist[u] = d;
    if (d > dist[farthest_node]) farthest_node = u;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
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
    dfs(1, -1, 0);
    int a = farthest_node;
    farthest_node = 0;
    dfs(a, -1, 0);
    cout << dist[farthest_node] << endl;
    return 0;
}
