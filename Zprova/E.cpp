#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> arvr(n, vector<int>(m));
    
    for (int i = 0; i < n; ++i) //linha
        for (int j = 0; j < m; ++j) //coluna
            cin >> arvr[i][j];
    
    // deixa impar par juntos
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int maca = arvr[i][j];
            if ((i + j) % 2 == 0) { //par
                if (maca % 2 != 0){
                    maca++; 
                } 
            } 
            else { //impar
                if (maca % 2 == 0) {
                    maca++; 
                }
            }
            cout << maca << " ";
        }
        cout << "\n";
    }

    return 0;
}
