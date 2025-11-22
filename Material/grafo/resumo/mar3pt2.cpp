#include <bits/stdc++.h>
using namespace std;


/// DFS busca em profundidade 

vector<int> adj[100005];
bool vis[100005];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u]){
        if(!vis[v]) dfs(v);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); // se for direcionado, tirar isso
    }

    dfs(1);
}

//////////////////////////

// BFS menor distancia em grafo sem peso

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int dist[100005];

int main(){
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    for(int i = 2; i <= n; i++) dist[i] = -1;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}


////////////////////////////////////////////

//// BICOLORABILIDADE - checar se grafo eh bipartido

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int color[200005];

bool bfs(int start){
    queue<int> q;
    q.push(start);
    color[start] = 1;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(color[v] == 0){
                color[v] = 3 - color[u]; // alterna 1 ↔ 2
                q.push(v);
            } 
            else if(color[v] == color[u]) return false;
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++)
        if(color[i] == 0)
            if(!bfs(i)){
                cout << "NAO É BIPARTIDO\n";
                return 0;
            }

    cout << "BIPARTIDO\n";
}


///////////////////////////////////////////

// TOPOSORT KAHN

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int indeg[200005];

int main(){
    int n, m;
    cin >> n >> m;

    while(m--){
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indeg[i] == 0)
            q.push(i);

    vector<int> topo;

    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);

        for(int v: adj[u]){
            indeg[v]--;
            if(indeg[v] == 0)
                q.push(v);
        }
    }

    if(topo.size() != n){
        cout << "CICLO – nao tem toposort\n";
        return 0;
    }

    for(int x : topo) cout << x << " ";
}


///////////////////////////

/// BFS Multicore

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int dista[200005];

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> marcados(k);
    for(int &x: marcados) cin >> x;

    while(m--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;

    for(int i = 1; i <= n; i++) dista[i] = -1;

    for(int x : marcados){
        dista[x] = 0;
        q.push(x);
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dista[v] == -1){
                dista[v] = dista[u] + 1;
                q.push(v);
            }
        }
    }

    for(int i = 1; i <= n; i++)
        cout << dista[i] << " ";
}



////////////////////////////////////

/// Detectar ciclos em grafos nao direcionados


#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
bool vis[200005];
bool hasCycle = false;

void dfs(int u, int parent){
    vis[u] = true;

    for(int v : adj[u]){
        if(!vis[v]) dfs(v, u);
        else if(v != parent) hasCycle = true;
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    cout << (hasCycle ? "TEM CICLO" : "NAO TEM CICLO");
}


///////////////////////////

// Diametro da arvore

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int dist[200005];

int bfs(int start){
    queue<int> q;
    q.push(start);

    for(int i = 1; i < 200005; i++) dist[i] = -1;
    dist[start] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int best = start;
    for(int i = 1; i < 200005; i++)
        if(dist[i] > dist[best]) best = i;

    return best;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int A = bfs(1);
    int B = bfs(A);

    cout << "Diametro = " << dist[B] << "\n";
}


/////////////////////////////////////////////


//// Componentes conexos

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
bool vis[200005];

void dfs(int u){
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfs(v);
}

int main(){
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b; 
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int comps = 0;

    for(int i = 1; i <= n; i++)
        if(!vis[i]){
            comps++;
            dfs(i);
        }

    cout << comps;
}
