#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int count = 0;

    // limita a ate raiz de n, ja q a^2 tem q ser menor ou igual a n. dessa forma b = n - a^2 vai ser maior q 0
    for(int a = 0; a * a <= n; a++){
        int b = n - a*a;
        if (b >= 0 && a + b*b == m){
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}


