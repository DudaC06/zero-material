#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long n, m, k;
    cin >> n >> m >> k;
    // pessoas, apts, diferenca
    
    vector<int> desejo(n);
    vector<int> apt(m);
    for(int i = 0; i < n; i++){
        cin >> desejo[i];
    }
    for(int i = 0; i < m; i++){
        cin >> apt[i];
    }
    
    // ordena em ordem crescente
    sort(desejo.begin(), desejo.end()); 
    sort(apt.begin(), apt.end());

    int tem_apt = 0;
    int a = 0; int d = 0;

    while(a<m && d<n){
        if (desejo[d] - k > apt[a]){ //n pega apt, pequeno
            a++; // passa pro prox apt
        }
        else if (apt[a] >= desejo[d] - k && apt[a] <= desejo[d] + k){ //pega apt
            tem_apt++;
            a++; d++; 
        }
        else{ //n pega apt, grande
            d++; //ve prox pessoa
        }    
    }

    cout << tem_apt;
    return 0;
}
