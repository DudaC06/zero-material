#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;

        int resto = a % b;
        if (resto == 0) cout << resto << "\n";
        else{
            int res = abs(b - resto);
            cout << res << "\n";
        }
    }
    return 0;
}


