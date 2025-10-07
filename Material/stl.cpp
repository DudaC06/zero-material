#include<bits/stdc++.h>
using namespace std;

int main(){
    
    vector<int> estrutura; //ex 

    //estruturas de dados
    estrutura.size(); // retorna o tamanho do vetor
    estrutura.empty(); // retorna se o vetor está vazio
    estrutura.begin(); // retorna o primeiro elemento do vetor
    estrutura.end(); // retorna o último elemento do vetor


    // vector: array dinâmico

    vector<int> lista; // cria um vetor vazio de inteiros
    vector<int> lista2(10); // cria um vetor de inteiros com 10 posições
    vector<int> lista3(10, 5); // cria um vetor de inteiros com 10 posições e inicializa todas com 5

    for (int i = 0; i < 10; i++){
        lista.push_back(i); // adiciona o elemento i no vetor
    }
    for (int i = 0; i < lista.size(); i++) cin >> lista[i]; // preenche o vetor com os valores digitados pelo usuário
    for( int x : lista) cout << x << " "; // imprime o vetor
    for (int i = 0; i < lista.size(); i++){
        cout << lista[i] << " "; // imprime o vetor
    }

    lista.push_back(10); // adiciona o elemento 10 no vetor
    lista.pop_back(); // remove o último elemento do vetor
    lista[0] = 5; // pode acessar como array 
    lista.front(); // acessa o primeiro elemento do vetor
    lista.back(); // acessa o último elemento do vetor
    lista.clear(); // limpa o vetor
    
    lista.insert(lista.begin() + 2, 20); // adiciona o elemento 20 na posição 2 do vetor
    lista.insert(lista.begin() + 2, 3, 30); // adiciona o elemento 30 na posição 2 do vetor 3 vezes
    lista.erase(lista.begin() + 2); // remove o elemento na posição 2 do vetor
    lista.erase(lista.begin() + 2, lista.begin() + 5); // remove os elementos da posição 2 até a posição 5 do vetor


    // ordenacao e busca
    sort(lista.begin(), lista.end()); // ordena o vetor
    sort(lista.begin(), lista.end(), greater<int>()); // ordena o vetor em ordem decrescente
    reverse(lista.begin(), lista.end()); // inverte o vetor
    random_shuffle(lista.begin(), lista.end()); // embaralha o vetor
    binary_search(lista.begin(), lista.end(), 5); // verifica se o elemento 5 está no vetor
    lower_bound(lista.begin(), lista.end(), 5); // retorna o iterador do primeiro elemento maior ou igual a 5
    upper_bound(lista.begin(), lista.end(), 5); // retorna o iterador do primeiro elemento maior que 5

    // up e lb retornam interadores ("ponteiros" para posições do vetor)
    // se quiser o indice subtraimos o interador do comeco do vetor
    // - lista.begin() para pegar o iterador do comeco do vetor
    // lower.bound(lista.begin(), v.end(),x) - lista.begin()
    // ou podemos usar a funcao distance(lista.begin(), iterador) para pegar a distancia entre o comeco do vetor e o iterador
    

    // lembrado 
    // lower bound: A menor posicao que aparece um numero maior ou igual que x no nosso vetor.
    // upper bound: A menor posicao que aparece um numero estritamente maior que x no nosso vetor.

    int i, j;

    //matriz com vetor
    vector<vector<int>> matriz(3, vector<int>(4)); // cria uma matriz 3x4
    vector<vector<int>> mat(3, vector<int>(4, 0)); // cria uma matriz 3x4 e inicializa todas as posições com 0
    matriz[i][j];  // acessa o elemento da linha i, coluna j

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            matriz[i][j] = i + j; // preenche a matriz com os valores da soma das posições
        }
    }
    
    // 
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[i].size(); j++) {
        cout << matriz[i][j] << " ";
        }
    cout << "\n";
    }
    matriz.push_back(vector<int>{1, 2, 3}); // adiciona uma linha na matriz
    matriz.pop_back(); // remove a última linha da matriz
    int linhas = matriz.size();
    int colunas = matriz[0].size();  // supondo que todas têm o mesmo tamanho




    //vetor de pares

    vector<pair<int, int>> pares; // cria um vetor de pares de inteiros
    vector<pair<int, int>> pares(5); // cria vetor com 5 pares (0,0)

    pares.push_back({1, 5});
    pares[0] = {1, 2}; // prenche com indice
    pares[1] = {3, 4};

    for (auto p : pares) {
        cout << p.first << " " << p.second << "\n"; // imprime os pares
    }   

    sort(pares.begin(), pares.end());  // ordena por p.first (padrão)
    sort(pares.begin(), pares.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second; // ordena por p.second
    });
    std::sort(início, fim, [](const Tipo& a, const Tipo& b) {
    // Defina a lógica de comparação aqui
    return a < b;  // Exemplo simples de comparação
    });



    cout << pares[0].first << "\n";   // imprime o primeiro valor do primeiro par
    cout << pares[1].second << "\n";  // imprime o segundo valor do segundo par


    return 0;
}