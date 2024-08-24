#include <iostream>
using namespace std;
int n;
int d[1004], dp[1004][1004];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            if (d[j] == d[j + i - 1]) dp[j][j + i - 1] = dp[j + 1][j + i - 2] + 1;
            for (int k = j + 1; k <= j + i - 1; k++)
                dp[j][j + i - 1] = max(dp[j][j + i - 1], dp[j][k - 1] + dp[k][j + i - 1]);
        }
    }
    cout << dp[1][n];
}