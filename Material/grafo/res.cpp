CONCEITOS FUNDAMENTAIS
---------------------------------
Um grafo é formado por vértices (nós) e arestas (ligações entre eles).
Pode ser:
- Direcionado / Não Direcionado
- Ponderado / Não Ponderado

Representações:
1. Lista de adjacência simples:
    vector<vector<int>> adj(n);
2. Lista ponderada:
    vector<vector<pair<int,int>>> adj(n); // {vizinho, peso}
*/

#include <bits/stdc++.h>
using namespace std;

/* ====================================================
   BFS (Breadth-First Search)
   - Busca em largura (nível por nível)
   - Ideal para encontrar menor caminho em grafos não ponderados
==================================================== */
void bfs(int start, vector<vector<int>>& adj) {
    vector<bool> vis(adj.size(), false);
    queue<int> q;
    q.push(start);
    vis[start] = true;

    cout << "Ordem da BFS: ";
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    cout << "\n";
}

/* ====================================================
   DFS (Depth-First Search)
   - Busca em profundidade
   - Ideal para detectar ciclos, componentes conexos, topological sort
==================================================== */
void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!vis[v])
            dfs(v, adj, vis);
    }
}

/* ====================================================
   DSU (Disjoint Set Union / Union-Find)
   - Estrutura usada em Kruskal para unir conjuntos
==================================================== */
struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

/* ====================================================
   KRUSKAL — Árvore Geradora Mínima (MST)
   - Ordena arestas por peso
   - Adiciona as menores que não formem ciclo
   - Usa DSU (Union-Find)
   Complexidade: O(E log E)
==================================================== */
int kruskal(int n, vector<tuple<int,int,int>>& edges) {
    sort(edges.begin(), edges.end()); // ordena por peso
    DSU dsu(n);
    int total = 0, usados = 0;

    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            total += w;
            usados++;
            if (usados == n-1) break;
        }
    }
    return total;
}

/* ====================================================
   PRIM — Árvore Geradora Mínima (MST)
   - Começa em um vértice e vai adicionando as menores arestas
   - Usa min-heap (priority_queue com greater<>)
   Complexidade: O(E log V)
==================================================== */
int prim(int n, vector<vector<pair<int,int>>>& adj) {
    vector<bool> inMST(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, 0}); // peso, vértice inicial
    int total = 0;

    while(!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        total += w;

        for (auto [v, peso] : adj[u]) {
            if (!inMST[v])
                pq.push({peso, v});
        }
    }
    return total;
}

/* ====================================================
   ENTRADAS E SAÍDAS COMUNS EM PROBLEMAS DE GRAFOS
====================================================

ENTRADAS:
---------------------------------
1. Grafo não ponderado:
    n m           → número de vértices e arestas
    u v (m vezes) → arestas

2. Grafo ponderado:
    n m
    u v w (m vezes) → arestas com peso

3. Grafos direcionados:
    mesma forma, mas (u → v)

SAÍDAS MAIS COMUNS:
---------------------------------
- Ordem de visita dos nós (DFS/BFS)
- Distâncias mínimas a partir de uma origem
- Número de componentes conexos
- Peso total da MST
- Lista de arestas da MST

==================================================== */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "===== EXEMPLO DE USO DOS ALGORITMOS =====\n\n";

    /* --------------------------------------------------
       Exemplo 1: BFS e DFS em grafo não ponderado
    -------------------------------------------------- */
    int n = 6;
    vector<vector<int>> adj(n);

    vector<pair<int,int>> edges = {
        {0,1}, {0,2}, {1,3}, {1,4}, {2,5}
    };
    for (auto [u,v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "BFS a partir do nó 0:\n";
    bfs(0, adj);

    cout << "\nDFS a partir do nó 0:\n";
    vector<bool> vis(n, false);
    dfs(0, adj, vis);
    cout << "\n\n";

    /* --------------------------------------------------
       Exemplo 2: MST com Kruskal e Prim
    -------------------------------------------------- */
    cout << "===== MST (Árvore Geradora Mínima) =====\n";

    int n2 = 6;
    vector<tuple<int,int,int>> edges2 = {
        {4,0,1}, {4,0,2}, {2,1,2}, {3,2,3}, {2,2,5},
        {4,2,4}, {3,3,4}, {3,4,5}, {2,5,3}
    };

    cout << "Peso total (Kruskal): " << kruskal(n2, edges2) << "\n";

    vector<vector<pair<int,int>>> adj2(n2);
    for (auto [w,u,v] : edges2) {
        adj2[u].push_back({v,w});
        adj2[v].push_back({u,w});
    }

    cout << "Peso total (Prim): " << prim(n2, adj2) << "\n";

    return 0;
}

/*
====================================================
RESUMO RÁPIDO FINAL

TRAVESSIAS:
-----------
- BFS → nível por nível, usa fila → menor caminho sem peso
- DFS → profundidade, usa recursão/pilha → componentes, ciclos

MST:
-----------
- Kruskal → ordena arestas + DSU
- Prim → heap + vértices visitados

ENTRADAS:
-----------
n m
u v (w)

SAÍDAS:
-----------
- Ordem da BFS/DFS
- Número de componentes
- Peso da MST

====================================================
*/