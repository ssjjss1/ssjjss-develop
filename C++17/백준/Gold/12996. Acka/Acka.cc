#include <iostream>
using namespace std;
const int mod = 1000000007;
int dp[54][54][54][54];
int n, j1, j2, j3;
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> j1 >> j2 >> j3;
  if (j1 + j2 + j3 < n) {
    cout << 0;
    return 0;
  }
  dp[0][0][0][0] = 1;
  for (int s = 1; s <= n; s++) {
    for (int a = 0; a <= j1; a++) {
      for (int b = 0; b <= j2; b++) {
        for (int c = 0; c <= j3; c++) {
          if (a > 0) dp[s][a][b][c] = (dp[s][a][b][c] + dp[s - 1][a - 1][b][c]) % mod;
          if (b > 0) dp[s][a][b][c] = (dp[s][a][b][c] + dp[s - 1][a][b - 1][c]) % mod;
          if (c > 0) dp[s][a][b][c] = (dp[s][a][b][c] + dp[s - 1][a][b][c - 1]) % mod;
          if (a > 0 && b > 0) dp[s][a][b][c] = (dp[s][a][b][c] + dp[s - 1][a - 1][b - 1][c]) % mod;
          if (a > 0 && c > 0) dp[s][a][b][c] = (dp[s][a][b][c] + dp[s - 1][a - 1][b][c - 1]) % mod;
          if (b > 0 && c > 0) dp[s][a][b][c] = (dp[s][a][b][c] + dp[s - 1][a][b - 1][c - 1]) % mod;
          if (a > 0 && b > 0 && c > 0) dp[s][a][b][c] = (dp[s][a][b][c] + dp[s - 1][a - 1][b - 1][c - 1]) % mod;
        }
      }
    }
  }
  cout << dp[n][j1][j2][j3];
}