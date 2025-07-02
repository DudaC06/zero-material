#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();

    int pt1 = 0, pt2 = 0;

    while(n--){
        string s;
        getline(cin, s);

        if(s[5] == '1'){
            pt1 += s[8] - '0';
        }
        else if(s[5] == '2'){
            pt2 += s[8] - '0';
        }
    }

    cout << pt1 << " x " << pt2 << "\n";

    return 0;
}