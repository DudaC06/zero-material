#include<bits/stdc++.h>
using namespace std;

int main(){
    float a, b;
    cin >> a >> b;

    float media = (a + b) / 2;

    if (media >= 7){
        cout << "Aprovado\n";
    }
    else if(media >= 4){
        cout << "Recuperacao\n";
    }
    else{
        cout << "Reprovado\n";
    }
    
    return 0;
}

