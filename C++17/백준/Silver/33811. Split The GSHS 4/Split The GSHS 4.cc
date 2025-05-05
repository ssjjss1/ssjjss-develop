#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    vector<int> v(n+4, 0);

    for (int i = 0; i < n - 3; i++) {
        if (s[i] == 'S' && s[i+1] == 'S' && s[i+2] == 'H' && s[i+3] == 'S') {
            v[i] = 1;
        } else if (s[i] == 'G' && s[i+1] == 'S' && s[i+2] == 'H' && s[i+3] == 'S') {
            v[i] = -1;
        }
    }

    int mx = 0, cx = 0;
    for (int i = 0; i < n; i++) {
        cx = max(0, cx + v[i]);
        mx = max(mx, cx);
    }

    cout << mx;
}