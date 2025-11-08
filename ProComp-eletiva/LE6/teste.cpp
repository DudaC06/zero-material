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
        } else if (u != p && start_node == -1) { // só atualiza se ainda não encontrou um ciclo
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
    parent.resize(n + 1, -1); // inicializamos corretamente
    visited.assign(n + 1, false);
    start_node = -1;
    end_node = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i, -1);
    }

    if (start_node == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> cycle;
        cycle.push_back(start_node);

        int node = end_node;
        // inserção lenta no início (pode gerar TLE em ciclos grandes)
        while (node != start_node) {
            cycle.insert(cycle.begin(), node); 
            node = parent[node];
        }

        cycle.push_back(start_node);

        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
        cout << "\n";
    }

    return 0;
}
