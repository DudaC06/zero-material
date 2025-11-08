#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> teams;
bool ok = true;

void dfs(int v, int t) {
    teams[v] = t;
    for (int u : adj[v]) {
        if (teams[u] == -1) {
            dfs(u, 1 - t);
        } else if (teams[u] == t) {
            ok = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    adj.resize(n);
    teams.assign(n, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (teams[i] == -1) {
            dfs(i, 0);
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << teams[i] + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
