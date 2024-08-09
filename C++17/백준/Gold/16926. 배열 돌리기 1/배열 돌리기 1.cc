#include<iostream>
using namespace std;
int n, m, k;
int d[304][304];
void g(int x1, int y1, int x2, int y2) {
    int t = d[x1][y1];
    for (int i = y1; i < y2; i++) d[x1][i] = d[x1][i + 1];
    for (int i = x1; i < x2; i++) d[i][y2] = d[i + 1][y2];
    for (int i = y2; i > y1; i--) d[x2][i] = d[x2][i - 1];
    for (int i = x2; i > x1; i--) d[i][y1] = d[i - 1][y1];
    d[x1 + 1][y1] = t;
}
void f() {
    int mn = min(n, m) / 2;
    for (int i = 1; i <= mn; i++) {
        int x1 = i, y1 = i;
        int x2 = n + 1 - i, y2 = m + 1 - i;
        for (int j = 0; j < k; j++) {
            g(x1, y1, x2, y2);
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> d[i][j];
        }
    }
    f();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << d[i][j] << " ";
        }
        cout << '\n';
    }
}