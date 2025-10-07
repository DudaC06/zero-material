#include <bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define EPS 1e-9

// ================================
// ========== MATEMÁTICA ==========
// ================================

// Retorna base^expoente (int). Cuidado com overflow!
int potencia = pow(2, 10); // 1024

// Retorna (base^expoente) % mod de forma eficiente, sem overflow
long long mod_pow(long long base, long long expo, long long mod) {
    long long res = 1;
    base %= mod;
    while (expo > 0) {
        if (expo & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        expo >>= 1;
    }
    return res; // resultado final do expoente modular
}

// Retorna o maior divisor comum entre dois números
int mdc = gcd(24, 36); // 12

// Retorna o menor múltiplo comum entre dois números
int mmc = lcm(4, 6); // 12

// Retorna true se n for primo, false caso contrário
bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// Retorna um vetor<bool> onde is_prime[i] = true se i for primo
vector<bool> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
        if (is_prime[i])
            for (int j = i*i; j <= n; j += i)
                is_prime[j] = false;
    return is_prime; // vetor de primalidade até n
}

// Retorna um vetor com os fatores primos de n (com multiplicidade)
vector<int> fatores(int n) {
    vector<int> f;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            f.push_back(i);
            n /= i;
        }
    }
    if (n > 1) f.push_back(n);
    return f; // vetor contendo os fatores primos de n
}

// Retorna a soma dos n primeiros inteiros naturais
long long soma_pa(long long n) {
    return (n * (n + 1)) / 2;
}

// Retorna n! (fatorial de n)
long long fatorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}

// Retorna o coeficiente binomial C(n, k) = n! / (k!(n-k)!)
long long binomial(int n, int k) {
    long long res = 1;
    for (int i = 1; i <= k; i++) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

// Retorna true se n for potência de 2, false caso contrário
bool is_pow2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}



// Retorna um vector com todos os divisores de n em ordem crescente
vector<int> divisores(int n) {
    vector<int> divs;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);  // i é divisor
            if (i != n / i)
                divs.push_back(n / i);  // n/i também é divisor, se diferente de i
        }
    }
    sort(divs.begin(), divs.end());  // ordenar para facilitar uso posterior
    return divs;
}

int main() {
    int n = 36;
    vector<int> d = divisores(n);
    cout << "Divisores de " << n << ": ";
    for (int x : d) cout << x << " ";
    cout << "\n";
    return 0;
}

// ==========================
// === PROGRESSÕES ===
// ==========================

// Soma de PA: S = n/2 * (2a1 + (n-1)d)
long long soma_pa(long long n, long long a1, long long d) {
    return n * (2*a1 + (n-1)*d) / 2;
}

// Soma de PG: S = a1 * (r^n - 1)/(r - 1), r != 1
double soma_pg(double a1, double r, int n) {
    if (r == 1) return a1 * n;
    return a1 * (pow(r, n) - 1) / (r - 1);
}

// -----------------------------------------------------------------

// ================================
// ======= GEOMETRIA 2D ==========
// ================================

// Retorna a distância euclidiana entre dois pontos
double distancia(double x1, double y1, double x2, double y2) {
    return hypot(x2 - x1, y2 - y1); // sqrt(dx^2 + dy^2)
}

// Retorna a distância ao quadrado entre dois pontos (evita raiz)
double dist2(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2, dy = y1 - y2;
    return dx * dx + dy * dy;
}

// Retorna a área de um triângulo com vértices (x1, y1), (x2, y2), (x3, y3)
double area_triangulo(double x1, double y1, double x2, double y2, double x3, double y3) {
    return fabs((x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0);
}

// Retorna o produto escalar entre dois vetores (a · b)
// Resultado > 0: ângulo < 90º, = 0: ortogonais, < 0: ângulo > 90º
double dot(pair<double, double> a, pair<double, double> b) {
    return a.first * b.first + a.second * b.second;
}

// Retorna o produto vetorial entre dois vetores (a × b)
// Resultado > 0: sentido anti-horário, < 0: horário, = 0: colineares
double cross(pair<double, double> a, pair<double, double> b) {
    return a.first * b.second - a.second * b.first;
}

// Retorna true se os 3 pontos forem colineares
bool colineares(double x1, double y1, double x2, double y2, double x3, double y3) {
    return area_triangulo(x1, y1, x2, y2, x3, y3) < EPS;
}

// Retorna o ângulo entre dois vetores em radianos (de 0 a π)
double angle_between(pair<double, double> a, pair<double, double> b) {
    return acos(dot(a, b) / (hypot(a.first, a.second) * hypot(b.first, b.second)));
}

// Rotaciona o ponto (x, y) theta radianos em torno da origem
// Retorna o novo ponto rotacionado
pair<double, double> rotate(double x, double y, double theta) {
    double cs = cos(theta), sn = sin(theta);
    return {x * cs - y * sn, x * sn + y * cs};
}


// Área triângulo usando coordenadas (Shoelace formula)
double area_triangulo_coords(double x1, double y1, double x2, double y2, double x3, double y3) {
    return fabs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
}

double diametro(double raio) {
    return 2.0 * raio;
}

// Distância entre dois pontos (x1,y1) e (x2,y2)
double distancia(double x1, double y1, double x2, double y2) {
    return hypot(x2 - x1, y2 - y1);
}

// Área do círculo: A = πr²
double area_circulo(double r) {
    return PI * r * r;
}

double a = area_circulo(5);          // área círculo raio 5
double d = distancia(0,0,3,4);       // distância entre (0,0) e (3,4) = 5

// Área do triângulo: A = (b * h)/2
double area_triangulo(double base, double altura) {
    return (base * altura) / 2;
}

// Área do retângulo: A = b * h
double area_retangulo(double base, double altura) {
    return base * altura;
}

// Área do trapézio: A = ((B + b)/2) * h
double area_trapezio(double B, double b, double h) {
    return ((B + b) / 2.0) * h;
}



// ================================
// === CONVERSÃO GRAUS ↔ RAD ===
// ================================

// Converte graus para radianos
double graus_para_rad(double graus) {
    return graus * PI / 180.0;
}

// Converte radianos para graus
double rad_para_graus(double rad) {
    return rad * 180.0 / PI;
}


