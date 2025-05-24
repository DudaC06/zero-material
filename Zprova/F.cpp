#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, k;
    cin >> n >> p >> k;

    vector<int> roda;
    for (int i = 1; i <= n; i++) {
        if (i != p) {
            roda.push_back(i);
        }
    }

    int pos;
    if (p == n)
        pos = 0; 
    else
        pos = p - 1; 

    int resp = (pos + k) % (n - 1); //anda k

    cout << roda[resp] << endl;

    return 0;
}