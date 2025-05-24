#include <iostream>
using namespace std;

int main(){
    string dna;
    cin >> dna;

    char letra = 'Z';
    int maior = 0; 
    int cont = 1;

    for (char c : dna){
        if(c == letra){
            cont++;
        }
        else{
            letra = c;
            if (cont > maior){
                maior = cont;
            }
            cont = 1;
        }
    }
    if (cont > maior){
        maior = cont;
    }

    cout << maior;
    return 0;
}