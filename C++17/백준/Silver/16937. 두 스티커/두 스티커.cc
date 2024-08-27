#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, t;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> t;
    vector<pair<int, int>> v(t);
    for (int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = { x, y };
    }
    int mx = 0;
    for (int i = 0; i < t; i++) {
        for (int j = i + 1; j < t; j++) {
            pair<int, int> st1 = v[i], st2 = v[j];
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    int x1 = st1.first, y1 = st1.second, x2 = st2.first, y2 = st2.second;
                    if (x == 1) swap(x1, y1);
                    if (y == 1) swap(x2, y2);
                    if (x1 + x2 <= m && max(y1, y2) <= n) mx = max(mx, x1 * y1 + x2 * y2);
                    if (max(x1, x2) <= m && y1 + y2 <= n) mx = max(mx, x1 * y1 + x2 * y2);
                }
            }
        }
    }
    cout << mx;
}