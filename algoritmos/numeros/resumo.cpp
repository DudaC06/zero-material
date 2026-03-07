#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// --- MDC e MMC ---
// MDC: Maior divisor comum; MMC: Menor múltiplo comum [cite: 80, 82]
// Complexidade: O(log(min(a, b))) [cite: 77]
void mdc_mmc(int a, int b) {
    int g = gcd(a, b); // MDC [cite: 81]
    int l = lcm(a, b); // MMC [cite: 83]
}

// --- DIVISORES ---
// Encontra todos os divisores de N testando ate sqrt(N) [cite: 114, 119]
vector<int> get_divisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) { // Pares de divisores [cite: 123]
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) divisors.push_back(n / i); // Adiciona o par [cite: 126]
        }
    }
    return divisors;
}

// --- FATORAÇÃO PRIMA ---
// Decompõe N em fatores primos e suas potências [cite: 134, 137]
// Complexidade: O(sqrt(n)) [cite: 9]
vector<pair<int, int>> get_prime_factors(int n) {
    vector<pair<int, int>> primes;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) { // Divide repetidamente [cite: 135]
            n /= i;
            cnt++;
        }
        if (cnt > 0) primes.push_back({i, cnt});
    }
    if (n > 1) primes.push_back({n, 1}); // Resto eh primo [cite: 139]
    return primes;
}

// --- CRIVO DE ERATOSTENES ---
// Marca números não-primos de 2 até N 
// Complexidade: O(N log log N)
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) // Marca multiplos 
                is_prime[j] = false;
        }
    }
    return is_prime;
}

int main() {
    // Exemplo de uso dos algoritmos acima
    return 0;
}




// ======================


#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;

/** --- BÁSICOS --- **/

// MDC e MMC: O(log(min(a, b))) [cite: 1]
void basic_math(int a, int b) {
    int g = gcd(a, b); // Maior divisor comum [cite: 2, 3]
    int l = lcm(a, b); // Menor múltiplo comum [cite: 3]
}

// Divisores: O(sqrt(n)) - Encontra pares de divisores [cite: 8]
vector<int> get_divisors(int n) {
    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n/i) div.push_back(n/i); // Evita duplicar se n for quadrado perfeito [cite: 8]
        }
    }
    return div;
}

// Fatoração Prima: O(sqrt(n)) - Fatores e suas potências [cite: 9, 11]
vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) { n /= i; cnt++; } // Divide repetidamente [cite: 9, 10]
        if (cnt > 0) factors.push_back({i, cnt});
    }
    if (n > 1) factors.push_back({n, 1}); // Se sobrar n, ele é primo [cite: 9, 11]
    return factors;
}

/** --- CRIVO E PRIMOS --- **/

// Crivo de Eratóstenes: O(n log log n) [cite: 15]
// Pré-processa primos de 2 até N marcando múltiplos [cite: 14]
vector<bool> sieve(int n) {
    vector<bool> is_p(n + 1, true);
    is_p[0] = is_p[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (is_p[i])
            for (int j = i * i; j <= n; j += i) is_p[j] = false;
    return is_p;
}

/** --- ARITMÉTICA MODULAR --- **/

// Exponenciação Rápida: O(log e) - Calcula (b^e) % m
ll fast_pow(ll b, ll e, ll m) {
    ll res = 1;
    while (e > 0) {
        if (e & 1) res = (res * b) % m;
        b = (b * b) % m;
        e >>= 1;
    }
    return res;
}

/** --- RECORRÊNCIA LINEAR (FIBONACCI) --- **/

// Estrutura para multiplicação de matrizes usada em Fibonacci O(log n)
struct Matrix {
    ll mat[2][2];
    Matrix() { mat[0][0]=mat[0][1]=mat[1][0]=mat[1][1]=0; }
    static Matrix identity() {
        Matrix res; res.mat[0][0] = res.mat[1][1] = 1;
        return res;
    }
    Matrix operator*(const Matrix& other) const {
        Matrix res;
        for(int i=0; i<2; i++)
            for(int j=0; j<2; j++)
                for(int k=0; k<2; k++)
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]);
        return res;
    }
};

// Calcula Fibonacci usando Matriz: [F(n), F(n-1)] = [1 1; 1 0]^n * [F(1), F(0)]
ll fibonacci_matrix(ll n) {
    if (n == 0) return 0;
    Matrix res = Matrix::identity();
    Matrix T; T.mat[0][0]=1; T.mat[0][1]=1; T.mat[1][0]=1; T.mat[1][1]=0;
    n--; // n-1 potências para F(n)
    while (n > 0) {
        if (n & 1) res = res * T;
        T = T * T;
        n >>= 1;
    }
    return res.mat[0][0];
}

int main() { return 0; }