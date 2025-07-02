#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    ll n, q;
    cin >> t;

    while(t--){
        cin >> n;
        vector<ll> array(n);
        vector<ll> somapref(n+1, 0);
        for(ll i = 0; i < n; i++){
            cin >> array[i];
            // soma do array atual com o anterior da pref
            somapref[i+1] = array[i] + somapref[i]; 
        } 
        cin >> q;
        ll l, r;
        for(ll i = 0; i< q; i++){
            cin >> l >> r;
            cout << somapref[r] - somapref[l-1] << " ";
        }
    }
    cout << "\n";
}