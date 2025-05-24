#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<char> alfabeto; // valores unicos
    string s;

    if (n >= 26){
        cin >> s;
        for (char c : s){
            alfabeto.insert(tolower(c));
        }
        if(alfabeto.size() == 26){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    else{
        cout << "NO\n";
    }

    return 0;
}