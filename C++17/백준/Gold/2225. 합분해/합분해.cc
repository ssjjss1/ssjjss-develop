#include <iostream>
using namespace std;
const int mod = 1000000000;
int n, k;
int dp[204][204];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i <= k; i++) dp[0][i] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      dp[i][j] = 0;
      for (int l = 0; l <= i; l++) {
        dp[i][j] = (dp[i][j] + dp[i - l][j - 1]) % mod;
      }
    }
  }
  cout << dp[n][k];
}