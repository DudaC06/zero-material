// Maratona Feminina de Programação da Unicamp 2024 - Soluções Comentadas
// Linguagem: C++ (com uso de <bits/stdc++.h> para facilitar)

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

// -------------------- Questão A - Arrumando Bandeiras --------------------
string flag_res;
void gera_bandeira(int n) {
    if (flag_res.size() >= 100000) return;
    if (n == 1) {
        flag_res += 'a';
        return;
    }
    gera_bandeira(n - 1);
    if (flag_res.size() < 100000)
        flag_res += (char)('a' + n - 1);
    gera_bandeira(n - 1);
}

void problemaA() {
    int n;
    cin >> n;
    flag_res.clear();
    gera_bandeira(n);
    cout << flag_res.substr(0, 100000) << '\n';
}

// -------------------- Questão B - Base Sob Ataque --------------------
vector<int> base_adj[50005];
int base_sala[50005];
int base_k, base_cortes;

int base_dfs(int u, int p, int lim) {
    int soma = base_sala[u];
    for (int v : base_adj[u]) {
        if (v == p) continue;
        int sub = base_dfs(v, u, lim);
        if (soma + sub > lim) base_cortes++;
        else soma += sub;
    }
    return soma;
}

bool base_pode(int lim) {
    base_cortes = 0;
    base_dfs(0, -1, lim);
    return base_cortes <= base_k;
}

void problemaB() {
    int n;
    cin >> n >> base_k;
    int total = 0;
    for (int i = 0; i < n; ++i) cin >> base_sala[i], total += base_sala[i];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        base_adj[a].push_back(b);
        base_adj[b].push_back(a);
    }
    int l = *max_element(base_sala, base_sala + n), r = total, ans = total;
    while (l <= r) {
        int m = (l + r) / 2;
        if (base_pode(m)) ans = m, r = m - 1;
        else l = m + 1;
    }
    vector<pair<int, int>> cortes;
    function<int(int, int)> dfs = [&](int u, int p) {
        int soma = base_sala[u];
        for (int v : base_adj[u]) {
            if (v == p) continue;
            int sub = dfs(v, u);
            if (soma + sub > ans) cortes.emplace_back(u + 1, v + 1);
            else soma += sub;
        }
        return soma;
    };
    dfs(0, -1);
    cout << cortes.size() << '\n';
    for (auto [a, b] : cortes) cout << a << ' ' << b << '\n';
}

// -------------------- Questão C - Ciclismo --------------------
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
void problemaC() {
    int A, B;
    cin >> A >> B;
    cout << gcd(A, A - B) << '\n';
}

// -------------------- Questão D - Definindo Funções --------------------
void problemaD() {
    int A[6][6];
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            cin >> A[i][j];

    vector<int> perm = {0, 1, 2, 3, 4, 5};
    int res = 0;
    do {
        int soma = 0;
        for (int i = 0; i < 6; ++i)
            soma += A[i][perm[i]];
        res = max(res, soma);
    } while (next_permutation(perm.begin(), perm.end()));
    cout << res << '\n';
}

// -------------------- Questão E - Entregando Medalhas --------------------
void problemaE() {
    int N, M, k, l;
    cin >> N >> M >> k >> l;
    vector<int> x(k); for (auto &v : x) cin >> v;
    vector<bool> destino(N, false);
    for (int i = 0; i < l; ++i) { int y; cin >> y; destino[y] = true; }

    vector<int> dp(N, 0); dp[0] = 1;
    int inv_k = modinv(k);
    for (int i = 0; i < M; ++i) {
        vector<int> nxt(N, 0);
        for (int j = 0; j < N; ++j) {
            if (dp[j]) {
                int qtd = dp[j] * inv_k % MOD;
                for (int d : x)
                    nxt[(j + d) % N] = (nxt[(j + d) % N] + qtd) % MOD;
            }
        }
        dp = nxt;
    }
    int ans = 0;
    for (int i = 0; i < N; ++i)
        if (destino[i]) ans = (ans + dp[i]) % MOD;
    cout << ans << '\n';
}

// -------------------- Questão F - Fluxo Máximo --------------------
vector<pair<int, int>> rede[200005];
bool caminho(int S, int T, int min_cap, int N) {
    vector<bool> vis(N + 1, false);
    queue<int> q; q.push(S); vis[S] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == T) return true;
        for (auto [v, c] : rede[u]) {
            if (c >= min_cap && !vis[v]) vis[v] = true, q.push(v);
        }
    }
    return false;
}
void problemaF() {
    int N, M, S, T;
    cin >> N >> M >> S >> T;
    int max_cap = 0;
    for (int i = 0; i < M; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        rede[A].emplace_back(B, C);
        max_cap = max(max_cap, C);
    }
    int l = 1, r = max_cap, res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (caminho(S, T, m, N)) res = m, l = m + 1;
        else r = m - 1;
    }
    cout << res << '\n';
}

// -------------------- Questão G - Girl Power --------------------
void problemaG() {
    int N, X;
    cin >> N >> X;
    vector<int> g(N); for (int &x : g) cin >> x;
    int amy = g[0];
    vector<int> resto(g.begin() + 1, g.end());
    sort(resto.begin(), resto.end());
    int soma = accumulate(resto.begin(), resto.end(), amy);
    vector<int> dp(soma + 1, 0); dp[amy] = 1;
    for (int gp : resto) {
        for (int i = soma - gp; i >= gp; --i)
            if (dp[i]) dp[i + gp] = (dp[i + gp] + dp[i]) % MOD;
    }
    int ans = 0;
    for (int i = X; i <= soma; ++i) ans = (ans + dp[i]) % MOD;
    cout << ans << '\n';
}

// -------------------- Questão H - Hiperlotação --------------------
void problemaH() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> clientes(N);
    for (auto &c : clientes) cin >> c.first >> c.second;

    priority_queue<int, vector<int>, greater<int>> atend;
    int max_pessoas = 0;
    for (int i = 0; i < N; ++i) {
        int chegada = clientes[i].first, dur = clientes[i].second;
        while (!atend.empty() && atend.top() <= chegada) atend.pop();
        if ((int)atend.size() < K)
            atend.push(chegada + dur);
        int esperando = i + 1 - atend.size();
        max_pessoas = max(max_pessoas, (int)atend.size() + esperando);
    }
    cout << max_pessoas << '\n';
}

// -------------------- Questão I - Inquietação Musical --------------------
void problemaI() {
    int N; cin >> N;
    cin.ignore();
    vector<string> versos(N);
    for (auto &v : versos) getline(cin, v);
    int M; cin >> M;
    unordered_map<string, int> notas;
    for (int i = 0; i < M; ++i) {
        string p; int x; cin >> p >> x;
        notas[p] = x;
    }
    int total = 0, melhor = 0, idx = 0;
    for (int i = 0; i < N; ++i) {
        stringstream ss(versos[i]); string w;
        int soma = 0;
        while (ss >> w) soma += notas[w];
        total += soma;
        if (soma > melhor || (soma == melhor && i > idx)) melhor = soma, idx = i;
    }
    cout << total << ' ' << (idx + 1) << '\n';
}

// -------------------- Função Main de Teste --------------------
// Descomente o problema que deseja testar

// signed main() {
//     problemaA();
//     problemaB();
//     problemaC();
//     problemaD();
//     problemaE();
//     problemaF();
//     problemaG();
//     problemaH();
//     problemaI();
//     return 0;
// }


