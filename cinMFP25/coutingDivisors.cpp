#include<bits/stdc++.h>
using namespace std;

int main(){
    long n;
    cin >> n;
    long x;

    for(int i = 0; i < n; i++){
        cin >> x;


    }

    return 0;
}

void sieve(){
    for (int i = 1; i < LIM; i++){
        for ( int j = i; j < LIM; j+= i){
            numdivisors[j]++;
        }
    }
}