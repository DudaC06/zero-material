#include<bits/stdc++.h>
using namespace std;

// primeiro e o diferente dos outros
bool vence(string a, string b){
    if ( (a == "rock" && b == "scissors") || (a == "scissors" && b == "paper")  || (a == "paper" && b == "rock") ){
        return true;
    }
    else{
        return false;
    }  
}

int main(){
    string f, m, s;
    cin >> f >> m >> s;

    // todas iguais ou diferentes
    if ((f == m && m == s) ||(f!=m && f!=s && m!=s)){
        cout << "?\n";
    }

    // 2 iguais
    else if(f==m){
        if (vence(s,f)) cout << "S\n";
        else cout << "?\n";
    }
    else if(f==s){
        if (vence(m,f)) cout << "M\n";
        else cout << "?\n";
    }
    else if(m==s){
        if (vence(f,s)) cout << "F\n";
        else cout << "?\n";
    }

    return 0;
}