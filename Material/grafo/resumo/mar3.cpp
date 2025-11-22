#include <bits/stdc++.h>
using namespace std;

/*
  ---------------------------
  Estruturas comuns usadas
  ---------------------------
  vector<int> adj[N];  -> lista de adjacência: para cada nó guarda os vizinhos
  bool vis[N];         -> marca nós visitados (DFS/BFS)
  int dist[N];         -> armazena distâncias (BFS)
  int indeg[N];        -> grau de entrada (Kahn / toposort)
  queue<int> q;        -> fila (BFS, Kahn)
  stack<int> st;       -> pilha (quando queremos ordem reversa em DFS)
  
  Observação sobre índices:
  - Exemplo usa nó indexado a partir de 1 (padrão em competições).
  - Ajuste para 0..n-1 se preferir.
*/

/* ===========================================================
   1) Exemplo: Representações de grafo
   - Matriz de adjacência (útil em grafos densos, O(n^2) memória)
   - Lista de adjacência (útil em grafos esparsos, O(n + m) memória)
   =========================================================== */

#if 0
// Exemplo de uso (apenas para leitura)
int main_representation(){
    int n = 5;
    // Matriz (inicialmente zeros)
    vector<vector<int>> mat(n+1, vector<int>(n+1, 0));
    // Lista
    vector<vector<int>> adj(n+1);

    // adicionar aresta 1-2
    mat[1][2] = mat[2][1] = 1; // não direcionado
    adj[1].push_back(2);
    adj[2].push_back(1);

    return 0;
}
#endif

/* ===========================================================
   2) DFS (Busca em profundidade) - recursiva
   - Complexidade: O(V + E)
   - Usa recursão (pilha implícita) ou pode-se implementar iterativamente com stack
   - Aplicações: componentes, detectar ciclos (com ajuste), ordens
   =========================================================== */

#if 0
// Tamanho máximo como exemplo. Ajuste conforme necessidade.
const int MAXN = 100005;
vector<int> adj_dfs[MAXN];
bool vis_dfs[MAXN];

// dfs: visita o nó u e todos os nós alcançáveis dele.
// comentários pontuais:
// - vis[u] evita revisitar nós.
// - a recursão empilha chamadas: até "matar" um ramo antes de voltar.
// - útil para enumerar componentes ou buscar propriedades locais.
void dfs(int u){
    vis_dfs[u] = true; // marca como visitado
    // processa u aqui (se quiser, por exemplo contar ou imprimir)
    for(int v : adj_dfs[u]){
        if(!vis_dfs[v]) dfs(v); // visita recursivamente vizinho não visitado
    }
}

// Exemplo de main comentado:
int main_dfs(){
    int n, m;
    // n: número de vértices, m: número de arestas
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b; cin >> a >> b;
        adj_dfs[a].push_back(b);
        adj_dfs[b].push_back(a); // remover para grafo direcionado
    }
    // iniciar DFS a partir do vértice 1
    dfs(1);
    return 0;
}
#endif

/* ===========================================================
   3) BFS (Busca em largura)
   - Complexidade: O(V + E)
   - Usa fila. Visita por camadas: ótima para menor distância em grafo não ponderado.
   - dist[u] armazena distância mínima (em número de arestas) desde a fonte.
   =========================================================== */

#if 0
vector<int> adj_bfs[MAXN];
int dist_bfs[MAXN];

int main_bfs(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int a,b; cin >> a >> b;
        adj_bfs[a].push_back(b);
        adj_bfs[b].push_back(a);
    }

    const int INF = 1e9;
    for(int i=1;i<=n;i++) dist_bfs[i] = INF;

    int source = 1;
    queue<int> q;
    dist_bfs[source] = 0; // distância da fonte pra ela mesma é 0
    q.push(source);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: adj_bfs[u]){
            if(dist_bfs[v] == INF){
                dist_bfs[v] = dist_bfs[u] + 1; // camada seguinte
                q.push(v);
            }
        }
    }

    // agora dist_bfs[i] tem a menor distância (ou INF se inacessível)
    return 0;
}
#endif

/* ===========================================================
   4) BFS Multisource
   - Inicia a fila com vários nós (vizinhos iniciais)
   - Resolve, por exemplo, "distância ao hospital mais próximo" 
   - Estratégia: marque dist=0 para cada fonte e empurre todas na fila.
   =========================================================== */

#if 0
vector<int> adj_multi[MAXN];
int dist_multi[MAXN];

int main_bfs_multi(){
    int n, m, k;
    cin >> n >> m >> k; // k = número de fontes (marcados)
    vector<int> sources(k);
    for(int i=0;i<k;i++) cin >> sources[i];

    while(m--){
        int a,b; cin >> a >> b;
        adj_multi[a].push_back(b);
        adj_multi[b].push_back(a);
    }

    const int INF = 1e9;
    for(int i=1;i<=n;i++) dist_multi[i] = INF;

    queue<int> q;
    for(int s : sources){
        dist_multi[s] = 0;
        q.push(s); // todas as fontes na fila inicialmente
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: adj_multi[u]){
            if(dist_multi[v] == INF){
                dist_multi[v] = dist_multi[u] + 1;
                q.push(v);
            }
        }
    }
    return 0;
}
#endif

/* ===========================================================
   5) Bicolorabilidade / Grafo Bipartido (usando BFS)
   - color[u] = 0 (não colorido), 1 ou 2
   - Para cada componente: se conflito, não é bipartido
   - Uso prático: verificar se grafo pode ser dividido em dois conjuntos sem arestas internas
   =========================================================== */

#if 0
vector<int> adj_bip[MAXN];
int color[MAXN]; // 0 = sem cor, 1 e 2 = as duas cores

bool bfs_bip(int start){
    queue<int> q;
    q.push(start);
    color[start] = 1; // escolhe cor 1 arbitrariamente

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: adj_bip[u]){
            if(color[v] == 0){
                color[v] = 3 - color[u]; // alterna 1 <-> 2
                q.push(v);
            } else if(color[v] == color[u]){
                // vizinho tem mesma cor -> não bipartido
                return false;
            }
        }
    }
    return true;
}

int main_bipartite(){
    int n, m; cin >> n >> m;
    while(m--){
        int a,b; cin >> a >> b;
        adj_bip[a].push_back(b);
        adj_bip[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        if(color[i] == 0){
            if(!bfs_bip(i)){
                cout << "NAO BIPARTIDO\n";
                return 0;
            }
        }
    }
    cout << "BIPARTIDO\n";
    return 0;
}
#endif

/* ===========================================================
   6) Toposort (Ordenação Topológica) - algoritmo de Kahn
   - Funciona apenas em DAGs (grafo direcionado acíclico)
   - indeg[v] guarda o grau de entrada de v
   - Colocamos todos indeg==0 na fila; removendo-os, atualizamos graus.
   - Se topo.size() != n, há ciclo.
   =========================================================== */

#if 0
vector<int> adj_kahn[MAXN];
int indeg[MAXN];

int main_kahn(){
    int n, m; cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v; // aresta u -> v
        adj_kahn[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++) if(indeg[i] == 0) q.push(i);

    vector<int> topo;
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v : adj_kahn[u]){
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }

    if((int)topo.size() != n){
        cout << "TEM CICLO, NAO EXISTE ORDEM TOPOLOGICA\n";
    } else {
        for(int x : topo) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
#endif

/* ===========================================================
   7) Detectar Ciclo em Grafo NÃO DIRECIONADO (DFS)
   - Na DFS, se visitarmos um vizinho que já está visitado e não é o pai,
     temos um ciclo.
   - parent é usado para evitar confundir a aresta por onde viemos.
   =========================================================== */

#if 0
vector<int> adj_cycle[MAXN];
bool vis_cycle[MAXN];
bool foundCycle = false;

void dfs_cycle(int u, int p){
    vis_cycle[u] = true;
    for(int v : adj_cycle[u]){
        if(!vis_cycle[v]) dfs_cycle(v, u);
        else if(v != p) foundCycle = true; // encontrou um retrocesso não-parental
    }
}

int main_cycle(){
    int n, m; cin >> n >> m;
    while(m--){
        int a,b; cin >> a >> b;
        adj_cycle[a].push_back(b);
        adj_cycle[b].push_back(a);
    }
    // caso o grafo seja desconexo, precisamos rodar para cada componente:
    for(int i=1;i<=n;i++)
        if(!vis_cycle[i]) dfs_cycle(i, -1);

    cout << (foundCycle ? "TEM CICLO\n" : "NAO TEM CICLO\n");
    return 0;
}
#endif

/* ===========================================================
   8) Diâmetro de Árvore (2 BFS)
   - Em árvore (grafo conexo sem ciclos), fazer BFS a partir de qualquer nó A,
     achar o nó mais distante B; depois BFS de B para achar distância máxima.
   - O resultado é o diâmetro (em número de arestas).
   =========================================================== */

#if 0
vector<int> adj_diameter[MAXN];
int dist_diam[MAXN];

int farthest(int start, int n){
    const int INF = 1e9;
    for(int i=1;i<=n;i++) dist_diam[i] = INF;
    queue<int> q;
    q.push(start);
    dist_diam[start] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : adj_diameter[u]){
            if(dist_diam[v] == INF){
                dist_diam[v] = dist_diam[u] + 1;
                q.push(v);
            }
        }
    }

    int best = start;
    for(int i=1;i<=n;i++){
        if(dist_diam[i] > dist_diam[best]) best = i;
    }
    return best;
}

int main_diameter(){
    int n; cin >> n;
    for(int i=0;i<n-1;i++){
        int a,b; cin >> a >> b;
        adj_diameter[a].push_back(b);
        adj_diameter[b].push_back(a);
    }

    int A = farthest(1, n);
    int B = farthest(A, n);
    // dist_diam[B] agora contem a distância entre A e B
    cout << "Diametro = " << dist_diam[B] << "\n";
    return 0;
}
#endif

/* ===========================================================
   9) Componentes conexos / Flood Fill (em matriz)
   - Em grafos: percorrer cada vértice não visitado com DFS/BFS
   - Em grids: usar DFS/BFS para "pintar" região conectada
   =========================================================== */

#if 0
// Flood fill em matriz (4-direções)
int R, C;
vector<string> grid;
bool seen[1005][1005];

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

void dfs_grid(int r, int c){
    seen[r][c] = true;
    for(int k=0;k<4;k++){
        int nr = r + dr[k], nc = c + dc[k];
        if(nr<0||nr>=R||nc<0||nc>=C) continue;
        if(seen[nr][nc]) continue;
        if(grid[nr][nc] == '#') continue; // exemplo: '#' = parede
        dfs_grid(nr, nc);
    }
}

int main_floodfill(){
    cin >> R >> C;
    grid.resize(R);
    for(int i=0;i<R;i++) cin >> grid[i];

    int components = 0;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(!seen[i][j] && grid[i][j] == '.'){
                components++;
                dfs_grid(i, j);
            }
        }
    }
    cout << components << '\n';
    return 0;
}
#endif

/* ===========================================================
   10) Observações finais e dicas de competição (comentadas)
   - Sempre escolha lista de adjacência quando grafo for esparso (m ~ n).
   - Lembre-se das complexidades: DFS/BFS = O(n + m).
   - Para grafos direcionados: cuidado ao testar ciclo (usar DFS com estados: 0=unvisited,1=visiting,2=done).
   - Para toposort também existe versão DFS (ordem reversa), além do Kahn.
   - Em grids, cuidado com delimitações e com o tamanho da pilha recursiva (use BFS/stack se risco de stack overflow).
   =========================================================== */

/* ===========================
   Bloco principal do arquivo
   ===========================
   Coloque abaixo o main que desejar usar para estudos; por enquanto deixamos um main demonstrativo comentado.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << "Arquivo de estudo: grafos_algorithms_study.cpp\n";
    cout << "Contem: DFS, BFS, BFS Multisource, Bipartite, Kahn(toposort), Ciclo, Diametro, FloodFill\n";
    cout << "Cada seção está comentada e envolvida por #if 0 / #endif para leitura.\n";
    cout << "Abra o arquivo em um editor e ative as seções que quiser compilar.\n";
    return 0;
}
