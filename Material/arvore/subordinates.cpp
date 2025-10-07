#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int size[200005];

void dfs(int u, int p) {
    size[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            size[u] += size[v];
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
    dfs(1, -1);
    for (int i = 1; i <= n; ++i) {
        cout << size[i] - 1 << " ";
    }
    cout << endl;
    return 0;
}
