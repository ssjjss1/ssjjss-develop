#include<iostream>
using namespace std;
int n, l, r, x;
int d[24];
int cnt = 0;
void f(int bit, int idx, int sum, int s) {
    if (sum > r) return;
    if (sum >= l && sum <= r && s >= 2) {
        int mx = 0, mn = 1e9+4;
        for (int j = 0; j < n; j++) {
            if (bit & (1 << j)) {
                mx = max(mx, d[j]);
                mn = min(mn, d[j]);
            }
        }
        if (mx - mn >= x) cnt += 1;
    }
    for (int i = idx; i < n; i++) {
        if (!(bit & (1 << i))) {
            f(bit | (1 << i), i + 1, sum + d[i], s + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++) cin >> d[i];
    f(0, 0, 0, 0);
    cout << cnt;
}