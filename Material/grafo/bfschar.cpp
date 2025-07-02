#include<bits/stdc++.h>
using namespace std;

// se os vertices fossem letras
// ao inves de lista de adjacencia iriamos usar um map com caracter como chave e vetor de caracteres como valor

int N, E;
map<char, vector<char>> lista_grafo;
map<char, bool> vis; // marca os visitados                       


vector<char> bfs(char x){
    // map já começa zerado, tudo false
    vis.clear(); // limpa o vertice
    vis[x] = true; // marca como visitado a origem

    vector<char> ans;
    queue<char> fila; // estrutura de controle para ve qm vai visitar
    fila.push(x);
    
    while(!fila.empty()){
        char u = fila.front(); // pega o primeiro da fila pra explorar
        fila.pop(); // remove da fila
        ans.push_back(u); // add na respota

        // ve os vizinho do vertice u
        for(char v : lista_grafo[u]){
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
        
        char u, w;
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
            vector<char> resposta = bfs(u);

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