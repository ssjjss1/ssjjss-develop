#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            int y;
            cin >> y;
            s.push(y);
        } else if (x == 2) {
            if (!s.empty()) {
                cout << s.top() << '\n';
                s.pop();
            } else {
                cout << -1 << '\n';
            }
        } else if (x == 3) {
            cout << s.size() << '\n';
        } else if (x == 4) {
            cout << (s.empty() ? 1 : 0) << '\n';
        } else if (x == 5) {
            if (!s.empty()) {
                cout << s.top() << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}