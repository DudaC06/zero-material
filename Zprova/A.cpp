#include<bits/stdc++.h>
using namespace std;

int main (){

    long n, m;
    cin >> n >> m;

    vector<int> som(n);
    
    for (int i = 0; i < n; i++) {
        cin >> som[i];
    }

    sort(som.begin(), som.end());  

    int pos = 0;
    for (int k = 1; k <= m; k++) {
        while (pos < n && som[pos] < k) {
            pos++;
        }
        int qtd = n - pos; // minutos >= k
        cout << qtd << " ";
    }
    cout << "\n";
    return 0;
}
