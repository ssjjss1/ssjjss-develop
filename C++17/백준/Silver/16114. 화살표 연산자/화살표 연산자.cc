#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    if (n == 0) {                
        cout << (x > 0 ? "INFINITE" : "0");
        return 0;
    }
    if (n == 1) {                
        cout << (x < 0 ? "INFINITE" : "0");
        return 0;
    }
    if (n % 2 == 1) {            
        cout << "ERROR";
        return 0;
    }

    int temp = n / 2;             
    if (x <= 0) {
        cout << 0;
        return 0;
    }
    cout << (x - 1) / temp;     
}