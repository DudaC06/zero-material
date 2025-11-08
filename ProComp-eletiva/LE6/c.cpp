#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;
int start_node, end_node;

bool dfs(int v, int p) {
    visited[v] = true;
    parent[v] = p;

    for (int u : adj[v]) {
        if (!visited[u]) {
            if (dfs(u, v)) return true;
        } else if (u != p) {
            start_node = u;
            end_node = v;
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);
    start_node = -1;
    end_node = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i, -1)) break;
    }

    if (start_node == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start_node);

        int node = end_node;
        while (node != start_node) {
            cycle.push_back(node);
            node = parent[node];
        }

        cycle.push_back(start_node);

        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
