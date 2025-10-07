#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin >> n){
        vector<int> heap(n);
        for(int i = 0; i < n; i++){
            heap[i] = n-i;
        }


        for(int v : heap) cout << v << " ";
        cout << "\n";
    }

    return 0;
}