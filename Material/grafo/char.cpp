#include<bits/stdc++.h>
using namespace std;

map<char, vector<char>> grafo;
map<char, bool> vis;
vector<char> ans;

vector<char> bfs(char s){
    vis.clear();
    vis[s] = true;

    vector<char> ans;
    // estrutura para controlar as visitar
    queue<char> fila;
    fila.push(s);

    while(!fila.empty()){
        // explora o primeiro da fila e remove ele
        char u = fila.front();
        fila.pop();
        ans.push_back(u);

        for(char v : grafo[u]){ // ve vizinhos de u
            if(!vis[v]){ // ve se já não foi visitado
                vis[v] = true;
                fila.push(v);
            }
        }
    }
    return ans;
}


int main(){
    int n, e; // vertices e arestas
    cin >> n >> e;

    char u, w;
    while(e--){ // monta o grafo
        cin >> u >> w;
        grafo[u].push_back(w);
        grafo[w].push_back(u);
    }   

    int q; // consultas
    cin >> q;
    
    while(q--){
        char s; // vertice de oridem
        cin >> s;
        vector<char> resp = bfs(s);

        for(int i = 0; i < (int)resp.size(); i++){
            cout << resp[i];
            if(i != (int)resp.size() - 1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}