#include<iostream>
using namespace std;
int g(int x, int y) {
    if (x == 0)return y;
    return g(y % x, x);
}
int f(int x, int y) {return x * y / g(x, y);}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        int mx = f(m, n);
        bool flag = false;
        for (int i = x; i <= mx; i += m) {
            if ((i - 1) % n +1 == y) {
                cout << i << '\n';
                flag = true;
                break;
            }
        }
        if (!flag) cout << -1 << '\n';
    }
}