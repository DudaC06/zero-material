#include<bits/stdc++.h>
using namespace std;

int main(){

    // inicializaçao da pilha
    stack<int> pilha;

    pilha.push(10); // empilha 10
    pilha.pop(); // remove o elemento do topo
    pilha.top(); // lê o valor do topo
    pilha.empty(); // retorna true se estiver vazia
    pilha.size(); // retora o num de elementos

    //dfs


    // vetor.assign(tamanho, valor);
    // serve para preencher ou substituir todo o conteúdo de um vetor com um valor padrão repetido ou com outro intervalo de dados


    int N, E;
    vector<vector<int>> lista_grafo;

    while(cin >> N >> E){

        // Preenche o vetor lista_grafo com n+1 vetores vazios de int (ou seja, cria n+1 listas de adjacência vazias).
        lista_grafo.assign(N + 1, vector<int>());
        // vai indexar a partir de 1 para ficar de 1 a 6 e não de 0 a 5
        
        /* 
        como o grafo ficaria
        lista_grafo = {
            {}, // vértice 0
            {}, // vértice 1
            {}, // vértice 2
            ...
            {}, // vértice n
            };
            
        */

        int u, w;
        // le as E arestas e armazena
        for(int i = 0; i < E; i++){
            cin >> u >> w;
            lista_grafo[u].push_back(w);
            // se o grafo for bidirecional (não-dirgido)
            lista_grafo[w].push_back(u);
        }
}

// A resposta da dfs é ordem em que os vértices são visitados durante a busca em profundidade.


    // representações grafo

    // matriz de adjacencia
    int n = 5;
    vector<vector<int>> adj(n, vector<int>(n, 0)); // matriz n x n inicializada com 0
    adj[0][1] = 1; // há uma aresta de 0 para 1

    /*
         0  1  2
        ----------
    0 |  0  1  1
    1 |  1  0  1
    2 |  1  1  0

    */


    // lista de adjacencia, para grafos não ponderados
    // Usamos vector<vector<int>> para grafos não ponderados, ou vector<vector<pair<int,int>>> para grafos ponderados.

    //não ponderado
    int n = 5;
    vector<vector<int>> adj(n); // lista de adjacência

    adj[0].push_back(1);
    adj[1].push_back(0); // grafo não dirigido

    // ponderado
    int n = 5;
    vector<vector<pair<int, int>>> adj(n); // {vizinho, peso}

    adj[0].push_back({1, 10}); // aresta de 0 para 1 com peso 10
    adj[1].push_back({0, 10});

    /*
    adj[0] = {1, 2}
    adj[1] = {0, 2}
    adj[2] = {1, 0}
    */



    //lista de arestas
    // bom para algoritmo baseado em arestas
    //Cada aresta é um par {u, v}. Armazena-se tudo num vector<pair<int, int>>

    vector<pair<int, int>> edges;

    edges.push_back({0, 1});
    edges.push_back({1, 2});
    edges.push_back({0, 2});

    /*
    edges = {
        {0, 1},
        {1, 2},
        {0, 2}
    }

    */



    // fila 
        queue<int> fila;

        // Inserindo elementos
        fila.push(10);
        fila.push(20);
        fila.push(30);

        // A fila agora é: [10, 20, 30]

        // Consultar o primeiro (frente)
        cout << "Frente: " << fila.front() << "\n"; // 10

        // Remover o primeiro
        fila.pop(); // remove 10

        // Agora a fila é: [20, 30]

        cout << "Nova frente: " << fila.front() << "\n"; // 20

        // Tamanho da fila
        cout << "Tamanho: " << fila.size() << "\n"; // 2

        // Verifica se está vazia
        if (fila.empty()) {
            cout << "Fila vazia\n";
        } else {
            cout << "Fila não vazia\n";
        }
        
        queue<int> q;

        q.push(10)	// Insere 10 no final da fila
        q.front()	// Retorna o elemento da frente
        q.pop()	    // Remove o da frente
        q.size()	// Retorna o tamanho da fila
        q.empty()	// Retorna se a fila está vazia (true/false)



        // imprimir o vetor sem um espaço no final
        for(int i = 0; i < (int)resposta.size(); i++) {
            cout << resposta[i];
            if(i != (int)resposta.size() - 1) cout << " ";
        }

        // sempre usar int antes de size para fazer comparações
        (int)v.size()
    return 0;
}