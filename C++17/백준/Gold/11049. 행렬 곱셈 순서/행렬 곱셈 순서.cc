#include <bits/stdc++.h>
using namespace std;
const int inf = 1e18 + 4;
typedef long long ll;
struct P {
    int a, b;
};
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<P> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].a >> v[i].b;
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l -1;
            dp[i][j] = inf;
            for (int k = i; k < j; k++) {
                ll m = dp[i][k] + dp[k + 1][j] + v[i].a * v[k].b * v[j].b;
                dp[i][j] = min(dp[i][j], m);
            }
        }
    }
    cout << dp[0][n - 1];
}