#include<bits/stdc++.h>
using namespace std;

int main() {
    const double PI = 3.14159265359;
    int r1, r2, r3;
    cin >> r1 >> r2 >> r3;

    int n, q;
    cin >> n >> q;

    vector<int> raios = {r1, r2, r3};

    for (int i = 0; i < q; i++) {
        int c1, l1, c2, l2;
        cin >> c1 >> l1 >> c2 >> l2;
        
        int raio1 = raios[c1-1];
        int raio2 = raios[c2-1];
        
        double circunferencia = 2 * PI * raio1; 
        double comprimentoPorParte = circunferencia / n; // tamanho setor
        double linhaCirc = abs(l1 - l2);
        linhaCirc = min(linhaCirc, n - linhaCirc); 

        linhaCirc *= comprimentoPorParte;
        
        double total;
        if (c1 == c2) {
            total = linhaCirc;
        } else {
            double distanciaRadial = abs(raio1 - raio2); 
            total = linhaCirc + distanciaRadial; 
        }
        
        cout << fixed << setprecision(6) << total << "\n";
    }

    return 0;
}
