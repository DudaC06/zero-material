#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int dist[MAXN], ans;

void dfs(int u, int p, int target) {
    if (dist[u] == target) ans++;
    for (int v : adj[u]) {
        if (v != p) {
            dist[v] = dist[u] + 1;
            dfs(v, u, target);
        }
    }
}

int main() {
    int n, target;
    cin >> n >> target;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dist[1] = 0;
    dfs(1, -1, target);
    cout << ans << endl;
    return 0;
}
