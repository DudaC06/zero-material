#include<bits/stdc++.h> //dica aula mfp
using namespace std;

int main(){
    long n, x;
    cin >> n >> x;
    vector<int> kids(n);

    for(int i = 0; i < n; i++){
        cin >> kids[i];
    }
    sort(kids.begin(), kids.end()); 
    
    int gondola = 0;
    int c = 0; //contador 
    int f = n-1;

    while(c<f){
        if ((kids[f] + kids[c]) > x ){ //crianca so
            gondola++;
            f--;
        }
        else{ //duas crinacas
            gondola++;
            f--;
            c++;
        }
    }

    if (c == f){ //sobrou uma crianca
        gondola++;
    }
    
    cout << gondola;
    return 0;
}