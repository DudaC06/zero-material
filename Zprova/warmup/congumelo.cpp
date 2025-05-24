#include<bits/stdc++.h>
using namespace std;

int main (){
    vector<int> x(4), y(4);

    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    int minimoX = *min_element(x.begin(), x.end());
    int maximoX = *max_element(x.begin(), x.end());
    int minimoY = *min_element(y.begin(), y.end());
    int maximoY = *max_element(y.begin(), y.end());

    int lado = max(maximoX - maximoX, maximoY - minimoY);
    int area = lado * lado;

    cout << area << "\n";
    return 0;
}