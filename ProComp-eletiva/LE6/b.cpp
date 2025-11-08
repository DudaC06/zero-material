#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

const int MAX_N = 1e5 + 5;

int parent[MAX_N];

int find_parent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find_parent(parent[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    long long total_weight = 0;
    int edges_used = 0;

    for (auto &edge : edges) {
        int root_u = find_parent(edge.u);
        int root_v = find_parent(edge.v);

        if (root_u != root_v) {
            parent[root_v] = root_u;
            total_weight += edge.w;
            edges_used++;

            if (edges_used == n - 1)
                break;
        }
    }

    if (edges_used != n - 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << total_weight << "\n";
    }

    return 0;
}
