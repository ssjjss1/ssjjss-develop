#include <iostream>
using namespace std;
const int mod = 1000000000;
long long dp[1000001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    int abs_n = abs(n);
    for (int i = 2; i <= abs_n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    if (n > 0) {
        cout << 1 << '\n' << dp[n] << '\n';
    } else if (n == 0) {
        cout << 0 << '\n' << 0 << '\n';
    } else {
        if (abs_n % 2 == 0) {
            cout << -1 << '\n';
        } else {
            cout << 1 << '\n';
        }
        cout << dp[abs_n] << '\n';
    }
}
