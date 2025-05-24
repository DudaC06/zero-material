#include <iostream>
using namespace std;

int main(){
    long n;
    cin >> n;
    long soma = 0; 
    long x;

    for (int i = 0; i < n-1; i++){
        cin >> x;
        soma += x;    
    }

    long soma_certa = ((n+1) * n) / 2;
    long num_falta = soma_certa - soma;
    cout << num_falta;
    return 0;
}