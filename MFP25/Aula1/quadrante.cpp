#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    //eixos do plano cartesiano
    if(x == 0 || y == 0){
        cout << "eixos\n";
    }
    else if(x > 0){
        if (y > 0){
            cout << "Q1\n";
        }
        else{
            cout << "Q4\n";
        }
    }
    else{ 
        if (y > 0){
            cout << "Q2\n";
        }
        else{
            cout << "Q3\n";
        }
    }
    return 0;
}