#include<bits/stdc++.h>
using namespace std;

int n, m;

bool triplo_check(const vector<vector<char>>& campo, int linha, int coluna) {
    // primiro traco
    if (coluna + 1 <= m ){
        if(campo[linha][coluna] != '*' || campo[linha][coluna + 1] != '*') return false;
    }
    else return false;

    // coluna do 3
    int linha_vertical = 0;
    while (linha + linha_vertical < n && campo[linha + linha_vertical][coluna + 1] == '*') {
        linha_vertical++;
    }
    if (linha_vertical < 5) return false;

    //meio
    bool meio = false;
    for (int i = linha + 2; i < linha + linha_vertical; i++) {
        if (coluna - 1 >= 0){
            if((campo[i][coluna] == '*') && (campo[i][coluna - 1] == '*')) {
                meio = true;
                break;
            }
        }
    }
    if (!meio) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 

    cin >> n >> m;
    vector<vector<char>> campo(n, vector<char>(m));

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            cin >> campo[i][j];
        }
    }

    bool triplo = false; //se nao for 3 eh 2
    for (int i = 0; i < (n-4); i++) { 
        for (int j = 0; j < (m-1); j++) { 
            if(triplo_check(campo,i,j)){
                triplo = true;
                break;
            }
        }
    }

    if(triplo) cout << "Triple Corolla Flower\n";
    else cout << "Double Petal Flower\n";

    
    return 0;
}
