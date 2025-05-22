#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int t = 0, b = 5000 + 1;    

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        t = max(t, x);
        b = min(b, y);
    }

    cout << (t * b % 7 + 1);
}