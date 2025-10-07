#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 

    int n, m;
    cin >> n >> m;
    vector<vector<int>> campo(n, vector<int>(m));
    
    char b;
    int xfungo, yfungo;
    int queijo = 0;
    int remove = 0;
   
    for (int i = 0; i < n; i++) { //linha
        for (int j = 0; j < m; j++) { //coluna
            cin >> b;
            campo[i][j] = b; 
            if(b == 'Q') queijo ++;
            else if (b == 'H'){
                xfungo = i;
                yfungo = j;
            }
        }
    }

    

    if(xfungo+1 < n){
        if(campo[xfungo+1][yfungo] == 'Q') remove++;
    }
    if(xfungo-1 >=0){
        if(campo[xfungo-1][yfungo] == 'Q') remove++;
    }
    if(yfungo+1 < m){
        if(campo[xfungo][yfungo+1] == 'Q') remove++;
    }
    if(yfungo-1 >=0){
        if(campo[xfungo][yfungo-1] == 'Q') remove++;
    }

    if(remove >= queijo) cout << "-1\n";
    else cout << remove << "\n";

    return 0;
}