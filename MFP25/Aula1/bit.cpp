#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int x = 0;

    for (int i = 0; i < n; i++){
        string oprc;
        cin >> oprc;
        
        for(char& c : oprc){
            if (c == '-'){
                x--;
                break;
            }
            else if (c == '+'){
                x++;
                break;
            }
        }
    }

    cout << x << "\n";
    return 0;
}