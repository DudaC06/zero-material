#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 7;
    //cin >> n;
    vector<int> intervalo = {1, 3, 4, 5, 6, 8, 10, 11};
    
    //for(int i = 0; i < 0; i++){
      //  cin >> intervalo[i];
    //}
    
    //sort(intervalo.begin(), intervalo.end());
    
    int x = 2;
   //cin >> x;
    bool achou = false;
    int inicio = 0, final = n-1;
    
    while(inicio <= final){
        int meio = (inicio + final) /2;
        
        if(intervalo[meio]== x){
            achou = true;
            break;
        }
        else if(intervalo[meio] > x){
            final = meio - 1; //descarta o meio e tudo a direita
        }
        else{
            inicio = meio + 1;//descarta o meio e tudo a esquerda
        }
    }
    
    if(achou){
        cout << "achou\n";
    }
    else{
        cout << "não achou\n";
    }
    return 0;
}
