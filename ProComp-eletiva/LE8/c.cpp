#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(6);
    ll n, a, b;
    cin >> n >> a >> b;

    ll min_sum = n * 1;
    ll max_sum = n * 6;

    if (b < min_sum || a > max_sum) { // impossuvel
        cout << 0.0 << "\n";
        return 0;
    }

    a = max(a, min_sum);
    b = min(b, max_sum);

    // soma iguak a A com I dados
    vector<ld> dp_atual(max_sum + 1, 0.0L);
    vector<ld> dp_prox(max_sum + 1, 0.0L);

    dp_atual[0] = 1.0L;

    for (ll dado = 1; dado <= n; dado++) {
        dp_prox.assign(dp_prox.size(), 0.0L);

        // intervalo das somas possiveis
        ll intrv_min = (dado - 1) * 1;
        ll intrv_max = (dado - 1) * 6;

        for (ll s = intrv_min; s <= intrv_max; s++) {
            ld p = dp_atual[s];
            if (p == 0.0L) continue;

            // pra cada valor da face, probabilidade p de ter a soma s
            for (ll face = 1; face <= 6; face++) {
                dp_prox[s + face] += p / 6.0L;
            }
        }

        dp_atual.swap(dp_prox);
    }

    // soma das probabilidades
    ld prob = 0.0L;
    for (ll s = a; s <= b; s++)
        prob += dp_atual[s];

    cout << prob << "\n";
    return 0;
}
