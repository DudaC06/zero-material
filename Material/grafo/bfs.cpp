#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>

int N, E;
vector<vi> lista_grafo;
vector<bool> vis; // marca os visitados                       


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


int main(){
    
    while(cin >> N >> E){
        lista_grafo.assign(N+1, vi()); // um vetor vazio para cada aresta
        
        int u, w;
        // le as E arestas
        for(int i = 0; i < E; i++){
            cin >> u >> w;
            lista_grafo[u].push_back(w);
            lista_grafo[w].push_back(u);
        }
        
        int q; // consultas
        cin >> q;
        while(q--){
            cin >> u; // vertice de origem pra consulta
            vi resposta = bfs(u);

            // imprime resposta
            for(int i = 0; i < (int)resposta.size(); i++){
                cout << resposta[i];
                if(i != (int)resposta.size() - 1) cout << " "; // pra n imprimur espaço extra no final
            }
        cout << "\n";
        }
    }


    return 0;
}