#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int b, sg, sb, p;
        cin >> b >> sg >> sb; 
        
        priority_queue<int> pg, pb; 
   
        for (int i = 0; i < sg; i++) {
            cin >> p;
            pg.push(p); 
        }
        for (int i = 0; i < sb; i++) {
            cin >> p;
            pb.push(p); 
        }

        while (!pg.empty() && !pb.empty()) {
            int battles = min(b, (int)min(pg.size(), pb.size())); // menos lemm ou menos batalha

            // vencedor
            vector<int> green_venc, blue_venc;

            for (int i = 0; i < battles; i++) {
                int greenPower = pg.top(); 
                int bluePower = pb.top(); 
                pg.pop();
                pb.pop();

                // verde vence
                if (greenPower > bluePower) {
                    green_venc.push_back(greenPower - bluePower); 
                }
                // azul vence
                else if (bluePower > greenPower) {
                    blue_venc.push_back(bluePower - greenPower); 
                }
            }

            //vencedores voltam
            for (int power : green_venc) {
                pg.push(power);
            }
            for (int power : blue_venc) {
                pb.push(power);
            }
        }


        if (pg.empty() && pb.empty()) {
            cout << "green and blue died\n"; 
        } 
        else if (pg.empty()) {
            cout << "blue wins\n"; 
            while (!pb.empty()) {
                cout << pb.top() << "\n"; 
                pb.pop();
            }
        } 
        else {
            cout << "green wins\n"; 
            while (!pg.empty()) {
                cout << pg.top() << "\n";
                pg.pop();
            }
        }

        // n imprimir espaco na ultima linha
       if (n > 0) cout << "\n"; 

    }

    return 0;
}
