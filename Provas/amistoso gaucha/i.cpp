#include<bits/stdc++.h>
using namespace std;

bool possivel(vector<int>& v1,  vector<int>& v2){

    // ordena e ve se é igual
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    if(v1 == v2){
        return true;
    }


    // rotaciona
    for (int i = 0; i < v2.size(); ++i) {
        // difernca de v1[0] com v2[i]
        int rotacao = (v2[i] - v1[0] + 360000) % 360000;

        // aplica a rotação em v1
        vector<int> rotated_v1(v1); //copia o vetor
        for (int j = 0; j < v1.size(); ++j) {
            rotated_v1[j] = (rotated_v1[j] + rotacao) % 360000;
        }

        // ordena a versão rotacionada e compara com v2
        sort(rotated_v1.begin(), rotated_v1.end());

        
        if (rotated_v1 == v2) {
            return true;
        }
    }

    // nenhum funcionar
    return false;

}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n;
    cin >> n; // ponteiros

    // 360.000 graus
    vector<int> ang1(n), ang2(n); 
    for(int i = 0; i < n; ++i) cin >> ang1[i];
    for(int i = 0; i < n; ++i) cin >> ang2[i];

    if(possivel(ang1, ang2)) cout << "possible\n";
    else cout << "impossible\n";

    return 0;
}


