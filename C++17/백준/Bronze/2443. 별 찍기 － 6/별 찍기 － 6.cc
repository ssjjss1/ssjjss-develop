#include <iostream>
using namespace std;
int n;
int main(){
    cin >> n;
    for(int i = n-1; i >= 0; i--){
        for(int j = n-2; j >= i; j--) cout << " ";
        for(int j = 1; j <= i*2 + 1; j++) cout << "*";
        cout << "\n";
    }
}