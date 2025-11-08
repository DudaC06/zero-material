#include<bits/stdc++.h>
using namespace std;

int melhor_dur = 0;
vector<int> melhor_seq;

void set_track(const vector<int>& faixas, int limite, int idx, vector<int>& seq, int duracao){

    if (duracao > limite){
        return;
    } 

    if (duracao > melhor_dur) {
        melhor_dur = duracao;
        melhor_seq = seq;
    }

    for (int i = idx; i < faixas.size(); i++) {
        seq.push_back(faixas[i]);
        set_track(faixas, limite, i + 1, seq, duracao + faixas[i]);
        seq.pop_back(); // volta
    }
}

int main() {
    int n, qntd;
    while (cin >> n >> qntd) {
        vector<int> faixas(qntd);


        for (int i = 0; i < qntd; ++i) {
            cin >> faixas[i];
        }

        // lemnra zerar
        melhor_dur = 0;
        melhor_seq.clear();
        vector<int> seq;

        set_track(faixas, n, 0, seq, 0);

        for (int duracao : melhor_seq) cout << duracao << " ";
        cout << "sum:" << melhor_dur << "\n";
    }

    return 0;
}
