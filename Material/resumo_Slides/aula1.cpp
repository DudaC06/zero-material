// ==============================
// AULA 1 - INTRODUÇÃO AO C++
// Complexidade, STL e Prefix Sum
// ==============================

#include <bits/stdc++.h>
using namespace std;

// ------------------------------
// FAST IO (desligar sincronização)
// ------------------------------
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

// ------------------------------
// TEMPLATE BASE
// ------------------------------
int main() {
    fast_io();

    int t; 
    cin >> t; // múltiplos casos de teste
    while (t--) {
        // código de cada caso
    }
    return 0;
}

// ------------------------------
// TIPOS DE DADOS
// ------------------------------
// int -> 4 bytes  (~ ±2e9)
// long long -> 8 bytes (~ ±9e18)
// double -> 8 bytes (15 dígitos de precisão)

// ------------------------------
// CONTAINERS STL
// ------------------------------
void containers_demo() {
    // VECTOR
    vector<int> v = {1, 2, 3};
    v.push_back(4);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end()); // remove duplicados

    // STRING
    string s = "abc";
    reverse(s.begin(), s.end());

    // MAP
    map<string, int> freq;
    freq["uva"]++;
    freq["maçã"]++;

    // SET
    set<int> S = {5, 1, 3};
    S.insert(2);
    S.erase(3);

    // STACK
    stack<int> st;
    st.push(10);
    st.pop();

    // QUEUE
    queue<int> q;
    q.push(10);
    q.pop();

    // DEQUE
    deque<int> dq = {1, 2, 3};
    dq.push_front(0);
    dq.push_back(4);

    // PRIORITY QUEUE (heap)
    priority_queue<int> pq; // max-heap
    pq.push(5);
    pq.push(10);
    pq.top(); // maior elemento

    // PAIR
    pair<int, string> p = {1, "um"};

    // TUPLE
    tuple<int, double, string> t = {1, 2.5, "oi"};
}

// ------------------------------
// ALGORITMOS STL ÚTEIS
// ------------------------------
void algorithms_demo() {
    vector<int> v = {3, 1, 4, 1, 5, 9};

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    int soma = accumulate(v.begin(), v.end(), 0);
    int minimo = *min_element(v.begin(), v.end());
    int maximo = *max_element(v.begin(), v.end());

    bool existe = binary_search(v.begin(), v.end(), 4);
    auto it1 = lower_bound(v.begin(), v.end(), 4);
    auto it2 = upper_bound(v.begin(), v.end(), 4);

    // próxima permutação lexicográfica
    do {
        // usa v
    } while (next_permutation(v.begin(), v.end()));
}

// ------------------------------
// PREFIX SUM
// ------------------------------
void prefix_sum_demo() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1), pref(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> a[i];

    // construção do prefix sum
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];

    // responder consultas [L, R]
    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << pref[R] - pref[L - 1] << '\n';
    }
}

/*
Complexidades:
---------------
Pré-processamento (Prefix Sum): O(N)
Consulta: O(1)
Sort: O(N log N)
Busca binária: O(log N)
Operações em vector/set/map: O(log N) ou O(1) dependendo do caso
*/

