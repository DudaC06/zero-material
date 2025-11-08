#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX_N = 20;
ll peso[MAX_N];
int n;
ll total_sum;
ll min_dif = LLONG_MAX;

void rec(int idx, ll group1_sum) {
    if (idx == n) {
        ll group2_sum = total_sum - group1_sum;
        ll dif = abs(group1_sum - group2_sum);
        if (dif < min_dif) {
            min_dif = dif;
        }
        return;
    }


    rec(idx + 1, group1_sum + peso[idx]);
    rec(idx + 1, group1_sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    total_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> peso[i];
        total_sum += peso[i];
    }

    rec(0, 0);

    cout << min_dif << "\n";

    return 0;
}
