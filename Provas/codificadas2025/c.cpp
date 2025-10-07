#include<bits/stdc++.h>
using namespace std;

set<string> todos(vector<set<string>>& pp){
    set<string> emComum = pp[0];
    for(int i = 1; i < pp.size(); i++){
        set<string> intersecao;

        //interseção das palavras
        for (auto& palavra : emComum) {
            if (pp[i].count(palavra)) { //ve se a palavra ta
                intersecao.insert(palavra);
            }
        }
        emComum = intersecao; //elimina as q nao foram ditar pela pessoa seguinte
    }
    return emComum;
}


int main(){
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 

   // imrpime a q td munod isso, mais frequnete e se empatar vai em ordem alfabetica

    int n; //qntd pessoas
    cin >> n;

    int p; //qntd palavra
    string s; //palavra dita
   
    map<string,int> contagem;
    vector<set<string>> pp; //palavra por pessoa 
    while(n--){  //pessoas
        cin >> p;
        set<string> p_temporaria;
        while(p--){ //palavras
            cin >> s;
            p_temporaria.insert(s);
            contagem[s]++;
        }
        pp.push_back(p_temporaria);
    }

    set<string> palavras_ditas = todos(pp);
    /*
    for (const auto& palavra : palavras_ditas) {
        cout << palavra << ": " << contagem[palavra] << '\n';
    }
    */

    // ordem impressao
    vector<pair<int, string>> resposta;
    for (const auto& palavra : palavras_ditas) {
        resposta.push_back({contagem[palavra], palavra});
    }
    sort(resposta.begin(), resposta.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first) {
            return a.second > b.second; 
    }
        return a.first > b.first; //freq
    });

    for (const auto& r : resposta) {
    cout << r.second << '\n';
    }
    return 0;
}