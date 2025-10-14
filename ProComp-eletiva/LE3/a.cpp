#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e5 + 5;
int n, q;
ll t[2 * N];


ll query(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += t[l++];  
        if (r & 1) res += t[--r]; 
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> t[n + i]; 
    }

    for (int i = n - 1; i > 0; --i) 
        t[i] = t[i << 1] + t[i << 1 | 1]; 

    while (q--) {
        int p, a;
        ll b;
        cin >> p >> a >> b;

        if (p == 1) {
            int x = a - 1;
            t[x += n] = b;  

            for (x >>= 1; x > 0; x >>= 1) {
                t[x] = t[x << 1] + t[x << 1 | 1];  
            }
        } else {
            cout << query(a - 1, b) << '\n';  
        }
    }

    return 0;
}
