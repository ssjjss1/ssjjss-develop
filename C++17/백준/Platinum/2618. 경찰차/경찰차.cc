#include<iostream>
using namespace std;
int n, m;
int x, y;
int ax[2001], ay[2001];
int dp[2001][2001];
int fsum(int a, int b) {
    return abs(ax[a] - ax[b]) + abs(ay[a] - ay[b]);
}
int f(int a, int b) {
    if (a == m + 1 || b == m + 1) return 0;
    if (dp[a][b]) return dp[a][b];
    int k = max(a, b) + 1;
    return dp[a][b] = min(f(a, k) + fsum(k, b), f(k, b) + fsum(a, k));
}
void g() {
    int a = 0, b = 1;
    for (int i = 2; i < m + 2; i++) {
        if (dp[i][b] + fsum(a, i) < dp[a][i] + fsum(i, b)) cout << 1, a = i;
        else cout << 2, b = i;
        cout << "\n";
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    ax[0] = 1, ay[0] = 1, ax[1] = n, ay[1] = n;
    for (int i = 2; i < m + 2; i++) {
        cin >> x >> y;
        ax[i] = x, ay[i] = y;
    }
    cout << f(0, 1) << "\n";
    g();
}