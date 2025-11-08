#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    int n;
    cin >> n;

    vector<ll> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    ll total = 0;
    for (int i = 0; i < n; i++) total += p[i];
    ll min_diff = total;

    for (int mask = 0; mask < (1 << n); ++mask) {
        ll group_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) group_sum += p[i];
        }
        ll other_group_sum = total - group_sum;
        ll diff = abs(group_sum - other_group_sum);
        min_diff = min(min_diff, diff);
    }

    cout << min_diff << endl;

    return 0;
}
