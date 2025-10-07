#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll fibonacho(ll& a, ll& b, ll& c){
    ll res = (c*a) + b;
    return res;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 

    //cada semana multiplicava A e somava B
    // passar de D inclina

    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    
    int semanas = 1;
    while(true){
        c = fibonacho(a, b, c);
        if(c <= d){
            semanas++;
        }
        else{
            break;
        }
    }

    cout << semanas << "\n";
    
    return 0;
}