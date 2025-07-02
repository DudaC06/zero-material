#include<bits/stdc++.h>
using namespace std;

int N, E;
vector<vector<int>> lista_grafo;
vector<bool> vis; // marca os visitados



vector<int> resp; // resposta da dfs  recursiva                         
void dfs_recursivo(int u) {
    vis[u] = true;
    resp.push_back(u); // visita o nó

    for (int viz : lista_grafo[u]) {
        if (!vis[viz]) {
            dfs(viz); // chama recursivamente
        }
    }
}


// vertice s marca a origem
vector<int> dfs(int s){
    vis.assign(N+1, false); // marca todos como não visitado
    vis[s] = true;
    vector<int> ans;

    stack<int> pilha;
    pilha.push(s);

    while(!pilha.empty()){
        int u = pilha.top(); // pega o vertice do topo para explorar
        pilha.pop();
        ans.push_back(u); // add na resposta

        // para cada vizinho w de u
        for(int w : lista_grafo[u]){
            if(!vis[w]){
                vis[w] = true;
                pilha.push(w);
            }
        }
    }

    return ans;
}


int main(){


    while(cin >> N >> E){

        lista_grafo.assign(N + 1, vector<int>());

        int u, w;
        // le as E arestas e armazena
        for(int i = 0; i < E; i++){
            cin >> u >> w;
            lista_grafo[u].push_back(w);
            // se o grafo for bidirecional (não-dirgido)
            lista_grafo[w].push_back(u);
        }
        int q; // consultas
        cin >> q;
        while(q--){
            cin >> u; // vertice de origem
            vector<int> resposta = dfs(u);
            for(int i = 0; i < (int)resposta.size(); i++){
                if(i > 0) cout << " ";
                cout << resposta[i];
            }
            cout << "\n";
        }
    }

    return 0;
}