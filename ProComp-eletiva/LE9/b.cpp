#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<int> v(m, 0);
    {
        int p = 0;
        for (int i = 1; i < m; i++) {
            while (p > 0 && s2[i] != s2[p]) {
                p = v[p - 1];
            }
            if (s2[i] == s2[p]) {
                p++;
            }
            v[i] = p;
        }
    }

    int resp = 0;
    int p = 0;

    for (int i = 0; i < n; i++) {
        while (p > 0 && s1[i] != s2[p]) {
            p = v[p - 1];
        }
        if (s1[i] == s2[p]) {
            p++;
        }
        if (p == m) {
            resp++;
            p = v[p - 1];
        }
    }

    cout << resp << "\n";
    return 0;
}
