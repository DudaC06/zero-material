#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    if(n % 2 == 1){ // impar
        ans++;
        n--;
    }
    
    if(n >= 8){
        ans++;
        n -= 8;
    }

    if(n >= 4){
        ans++;
        n -= 4;
    }

    if(n >= 2){
        ans++;
        n -= 2;
    }
    
    cout << ans;
    return 0;
}