#include<bits/stdc++.h>
using namespace std;

string mul_string(const string& str, int vezes) {
    string resultado = "";  

    for (int i = 0; i < vezes; i++) {
        resultado += str;
    }
    return resultado;
}

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int k;
    cin >> k;
    int f = 0, l1 = 0, l2 = 0, l4 = 0;

    if(k < 4){ // ultima incompleta
        switch(k%4){
            case 3:
                l1++;
                l2++;
                f++;
                break;
            case 2:
                l1++;
                l2++;
                break;
            case 1:
                l1++;
                break;
            default:
                break;  
            }
    }
    else{ //preenche ultima
        f++;
        l1++;
        l2++;
        l4++;
        k -= 4;

        //preenche fileiras de 3
        int resto = k/3; 
        l1+= resto;
        l2+= resto;
        l4+= resto;

        // ve se tem fileiras de 3 incompletas
        if(k%3 != 0){
            switch(k%3){
            case 2:
                l1++;
                l2++;
                break;
            case 1:
                l1++;
                break;
            default:
                break;  
            }
        }
    }


    // impressaooo
    // 11 assentos pro linha
    // linha 1 ok
    cout << "+------------------------+\n";


    // linha 2 ok
    cout << "|";
    // O. * l1
    string um_Pren = mul_string("O.", l1);
    cout << um_Pren;
    // #. * 11-l1
    string um_NaoPren = mul_string("#.", 11 - l1);
    cout << um_NaoPren;
    cout << "|D|)\n";


    // linha 3 ok
    cout << "|";
    // O. * l2
    string dois_Pren = mul_string("O.", l2);
    cout << dois_Pren;
    // #. * 11-l2
    string dois_NaoPren = mul_string("#.", 11 - l2);
    cout << dois_NaoPren;
    cout << "|.|\n";


    // linha 4 ok
    if(f == 1) cout << "|O.......................|\n";
    else cout << "|#.......................|\n";


    //linha 5 ok
    cout << "|";
    // O. * l4
    string quatro_Pren = mul_string("O.", l4);
    cout << quatro_Pren;
    // #. * 11-l4
    string quatro_NaoPren = mul_string("#.", 11 - l4);
    cout << quatro_NaoPren;
    cout << "|.|)\n";


    //linha 6 ok
    cout << "+------------------------+\n";

    return 0;
}

/*

+------------------------+  ok
|O.O.O.#.#.#.#.#.#.#.#.|D|)  ok
|O.O.O.#.#.#.#.#.#.#.#.|.| ok
|O.......................|  ok
|O.O.#.#.#.#.#.#.#.#.#.|.|) ok
+------------------------+  ok



*/