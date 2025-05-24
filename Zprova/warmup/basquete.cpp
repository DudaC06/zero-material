#include<bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin >> n;

    int p1 = 0, p2 = 0;

    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s); 

        if (s[5] == '1') { 
            p1 += s[7] - '0'; // char pra int
        } else { 
            p2 += s[7] - '0';
        }
    }

    cout << p1 << " x " << p2 << "\n";

    return 0;
}