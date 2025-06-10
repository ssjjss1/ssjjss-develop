#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        double x;
        string ch;
        cin >> x >> ch;

        cout << fixed << setprecision(4);

        if (ch == "kg") {
            cout << x * 2.2046 << " lb\n";
        } else if (ch == "lb") {
            cout << x * 0.4536 << " kg\n";
        } else if (ch == "l") {
            cout << x * 0.2642 << " g\n";
        } else if (ch == "g") {
            cout << x * 3.7854 << " l\n";
        }
    }
}