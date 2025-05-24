#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;

    int resultado;
    if (x > 5){
        resultado = x / 5;
        if (x % 5 != 0){
            resultado++;
        }
    }
    else{
        resultado = 1;
    }

    cout << resultado << "\n";
    return 0;
}