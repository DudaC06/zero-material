#include<bits/stdc++.h>
using namespace std;

int main(){
    int p1, c1, p2, c2;
    cin >> p1 >> c1 >> p2 >> c2;

    if ((c1*p1)>(c2*p2)){
        cout << "-1\n";
    }
    else if ((c1*p1)<(c2*p2)){
        cout << "1\n";
    }
    else{
        cout << "0\n";
    }
    return 0;
}