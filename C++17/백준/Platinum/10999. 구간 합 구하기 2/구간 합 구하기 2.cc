#include<iostream>
using namespace std;
int n, m, k;
long long b[1000001], c[1000001];
void f(long long tr[], int x, long long val) {
    while (x <= n) {
        tr[x] += val;
        x += (x & -x);
    }
}
long long g(long long tr[], int x) {
    long long sum = 0;
    while (x > 0) {
        sum += tr[x];
        x -= (x & -x);
    }
    return sum;
}
long long sum(int x) {
    return g(b, x) * x + g(c, x);
}
void Range(int l, int r, long long val) {
    f(b, l, val);
    f(b, r + 1, -val);
    f(c, l, val * (1 - l));
    f(c, r + 1, val * r);
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        Range(i, i, x);
    }
    m += k;
    while (m--) {
        int x;
        cin >> x;
        if (x == 1) {
            int y, z;
            long long val;
            cin >> y >> z >> val;
            Range(y, z, val);
        }
        else {
            int y, z;
            cin >> y >> z;
            cout << sum(z) - sum(y - 1) << '\n';
        }
    }
}