#include<bits/stdc++.h>
using namespace std;

int main (){
    long t;
    cin >> t;

    for(int i = 0; i < t; i++){
        long long k1, k2, k3;
        cin >> k1 >> k2 >> k3;
        
        if (k1 == k2) {
            cout << k3 << "\n";
        } 
        else if (k1 == k3) {
            cout << k2 << "\n";
        } else {
            cout << k1 << "\n";
        }
    }

    return 0;
}