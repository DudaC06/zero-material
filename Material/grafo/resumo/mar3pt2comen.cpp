#include <bits/stdc++.h>
using namespace std;

/// =====================================================================
/// DFS – Busca em Profundidade
/// Lógica: a DFS tenta ir o mais fundo possível antes de voltar.
/// É como seguir um corredor até o fim e só depois procurar caminhos paralelos.
/// =====================================================================

vector<int> adj[100005];
bool vis[100005];

void dfs(int u){
    vis[u] = true;  
    // Marca o nó como visitado — evita loops infinitos.

    for(int v : adj[u]){
        // Para cada vizinho...

        if(!vis[v]) dfs(v);
        // Se ainda não visitou, chamamos recursivamente.
        // A pilha da recursão "guarda" o caminho atual.
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a); 
        // Se o grafo fosse direcionado, remover essa linha.
    }

    dfs(1); 
    // A DFS vai explorar toda a componente conectada do nó 1.
}

//////////////////////////

// =====================================================================
// BFS – Busca em Largura
// Lógica: a BFS visita em camadas (distância crescente).
// Por isso encontra a MENOR distância em grafos não ponderados.
// =====================================================================

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
    // A distância da fonte para ela mesma é zero.

    for(int i = 2; i <= n; i++) dist[i] = -1;
    // Usamos -1 para marcar "não visitado".

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int v : adj[u]){
            if(dist[v] == -1){
                // Se nunca foi visitado...

                dist[v] = dist[u] + 1;
                // A distância é a dos pais + 1 (uma aresta a mais).

                q.push(v);
                // Entra no final da fila → garante visita por camadas.
            }
        }
    }
}

////////////////////////////////////////////

//// =====================================================================
/// BICOLORABILIDADE – Checar se um grafo é bipartido
/// Lógica: um grafo é bipartido se podemos alternar cores 1 e 2
/// e NUNCA encontrar duas cores iguais em vértices adjacentes.
/// =====================================================================

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int color[200005];

bool bfs(int start){
    queue<int> q;
    q.push(start);
    color[start] = 1;  
    // Começamos pintando com cor 1.

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int v : adj[u]){
            if(color[v] == 0){
                // Se ainda não foi pintado, pintamos com a cor oposta:

                color[v] = 3 - color[u]; 
                // 3 - 1 = 2, 3 - 2 = 1.
                q.push(v);
            } 
            else if(color[v] == color[u]) 
                // Se o vizinho tem a MESMA cor → não bipartido.
                return false;
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
        // Grafo não direcionado.
    }

    // Pode ter vários componentes, então testamos todos.
    for(int i = 1; i <= n; i++)
        if(color[i] == 0)
            if(!bfs(i)){
                cout << "NAO É BIPARTIDO\n";
                return 0;
            }

    cout << "BIPARTIDO\n";
}

///////////////////////////////////////////

// =====================================================================
// TOPOSORT – Algoritmo de Kahn
// Lógica: sempre removemos nós de grau de entrada zero.
// É como resolver tarefas cujos pré-requisitos já estão completos.
// Se sobrar nó com grau > 0 → existe ciclo.
// =====================================================================

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
        // Todo v depende de u → grau de entrada aumenta.
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(indeg[i] == 0)
            q.push(i);  
    // Começamos pelos nós que não dependem de ninguém.

    vector<int> topo;

    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);

        for(int v: adj[u]){
            indeg[v]--;
            // "Removemos" a dependência u -> v

            if(indeg[v] == 0)
                q.push(v);
        }
    }

    if(topo.size() != n){
        // Se sobrou algo com indeg > 0 → ciclo.
        cout << "CICLO – nao tem toposort\n";
        return 0;
    }

    for(int x : topo) cout << x << " ";
}

///////////////////////////

/// =====================================================================
/// BFS Multisource
/// Lógica: vários pontos começam com distância 0 ao mesmo tempo.
/// A BFS descobre o mais próximo de QUALQUER fonte.
/// =====================================================================

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
        // Todos os marcados são fontes simultâneas.
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

/// =====================================================================
/// Detectar ciclos em grafos NÃO direcionados
/// Lógica: se encontramos um vizinho que já foi visitado
/// e ele NÃO é o pai da DFS → existe ciclo.
/// =====================================================================

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
bool vis[200005];
bool hasCycle = false;

void dfs(int u, int parent){
    vis[u] = true;

    for(int v : adj[u]){
        if(!vis[v]) 
            dfs(v, u);  
        else if(v != parent) 
            // Visitado e não é o pai → aresta de retorno → ciclo.
            hasCycle = true;
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

// =====================================================================
/// Diâmetro da Árvore
/// Lógica:
/// 1) BFS de qualquer nó → encontra uma ponta do maior caminho (A)
/// 2) BFS de A → encontra a outra ponta (B)
/// 3) dist[A][B] é o diâmetro
/// =====================================================================

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
        if(dist[i] > dist[best]) 
            best = i;  
    // Retorna o nó mais distante.

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

    int A = bfs(1);  // uma ponta
    int B = bfs(A);  // outra ponta

    cout << "Diametro = " << dist[B] << "\n";
}

/////////////////////////////////////////////

//// =====================================================================
/// Componentes Conexos
/// Lógica: cada DFS completa cobre exatamente 1 componente.
/// =====================================================================

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
            comps++;     // achamos uma nova componente
            dfs(i);
        }

    cout << comps;
}
