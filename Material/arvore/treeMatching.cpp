#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int dp[200005][2];

void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = -1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }
    dp[u][1]++;
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
    cout << max(dp[1][0], dp[1][1]) << endl;
    return 0;
}
