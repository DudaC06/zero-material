#include<bits/stdc++.h>
using namespace std;

void dijkstra(int origem, const vector<vector<pair<int, int>>>& grafo, vector<int>& distancia){
    int V = grafo.size();
    distancia.assign(V, INF);
    distancia[origem] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> fila;
    fila.push({0, origem});

    while (!fila.empty()) {
        int dist_u = fila.top().first;
        int u = fila.top().second;
        fila.pop();

        if (dist_u > distancia[u]) continue;

        for (auto [v, peso] : grafo[u]) {
            if (distancia[u] + peso < distancia[v]) {
                distancia[v] = distancia[u] + peso;
                fila.push({distancia[v], v});
            }
        }
    }
}













// Definimos um valor muito alto para representar "infinito"
const int INF = numeric_limits<int>::max();

// Função de Dijkstra
// Recebe: vértice de origem, grafo (lista de adjacência), vetor de distâncias
void dijkstra(int origem, const vector<vector<pair<int, int>>>& grafo, vector<int>& distancia) {
    int V = grafo.size(); // Número de vértices no grafo

    // Inicializa todas as distâncias com infinito
    distancia.assign(V, INF);

    // A distância da origem para ela mesma é 0
    distancia[origem] = 0;

    // Fila de prioridade para escolher o próximo vértice com menor custo
    // Armazena pares (distância acumulada, vértice)
    // É um min-heap: o menor custo tem prioridade
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> fila;
    fila.push({0, origem}); // Começamos com a origem, custo 0

    // Enquanto houver vértices na fila para visitar
    while (!fila.empty()) {
        // Pega o vértice com menor distância acumulada até agora
        int dist_u = fila.top().first; // custo até u
        int u = fila.top().second;     // vértice u
        fila.pop(); // Remove da fila

        // Se a distância que tiramos da fila for maior que a atual, ignora (já foi atualizado antes)
        if (dist_u > distancia[u]) continue;

        // Para cada vizinho de u
        for (auto [v, peso] : grafo[u]) {
            // Se o caminho atual até u + peso da aresta for menor que a distância atual até v
            if (distancia[u] + peso < distancia[v]) {
                // Atualiza a menor distância até v
                distancia[v] = distancia[u] + peso;

                // Adiciona v na fila para ser processado futuramente
                fila.push({distancia[v], v});
            }
        }
    }
}

















vi bfs(int x){
    vis.assign(N+1, false); // marco todos os vertices como não viusitados
    vis[x] = true; // marca como visitado a origem

    vi ans;
    queue<int> fila; // estrutura de controle para ve qm vai visitar
    fila.push(x);
    
    while(!fila.empty()){
        int u = fila.front(); // pega o primeiro da fila pra explorar
        fila.pop(); // remove da fila
        ans.push_back(u); // add na respota

        // ve os vizinho do vertice u
        for(int v : lista_grafo[u]){
            if(!vis[v]){ // ve se já foi visitado
                vis[v] = true;
                fila.push(v);
            }
        }
    }

    return ans;
}


