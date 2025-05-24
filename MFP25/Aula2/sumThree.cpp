#include<bits/stdc++.h>
using namespace std;

void somaTres(vector<pair<int, int>>& v, int n, int x){
    //aponta pro incio e fim
    
    for(int i = 0; i < n; i++){
        int l = 0, r = n - 1;
        int alvo = x - v[i].first;

        // nao deixa ponteiros se ultrapassarem
        while (l < r){
            int soma = v[l].first + v[r].first;

            if(soma > alvo) r--; //diminui o maior
            else if (soma < alvo) l++; //aumenta o menor
            else{ // acertou
                if(l != i && r!= i){ // verifica se i nao e igual
                    cout << v[l].second << " " << v[r].second << " " << v[i].second << "\n";;
                    return;
                }
                else break;
            }
        }

    }
    cout << "IMPOSSIBLE\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;

    vector<pair<int,int>> array(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        array[i] = {a, i+1};
    }

    sort(array.begin(), array.end());
    somaTres(array, n, x);
    
    return 0;
}