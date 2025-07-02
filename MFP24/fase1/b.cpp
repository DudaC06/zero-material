#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<pair<int, int>> vertices;
    for(int i = 0; i < 4; i++){
        int a, b;
        cin >> a >> b;

        vertices.push_back({a,b});
    }

    for(int i = 1; i < 4; i++){
        if(vertices[0].first != vertices[i].first){
            int lado = abs(vertices[0].first - vertices[i].first);
            int area = lado * lado;
            cout << area << "\n";
            break;
        }
    }

    return 0;
}