#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, tam = 100005;
    cin >> n >> q;
    vector<int> x(n+1, 0), pref(tam, 0);

    for (int i = 1; i <= n; i++){
        cin >> x[i];
        pref[x[i]] ++;
    }

    for(int i=1;i <= tam; i++){
        pref[i] += pref[i-1];
    }

    int l, r;
    for(int i=1; i <=q; i++){
        cin >> l >> r;
        cout << "Tem " << pref[r]-pref[l-1] << "carros entre l e r\n";
    }
    return 0;
}
