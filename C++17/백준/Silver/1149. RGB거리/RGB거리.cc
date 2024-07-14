#include <iostream>
using namespace std;
int n;
long long dp[1001][4];
int a[1001][4];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> a[i][j];
    }
  }
  dp[1][1] = a[1][1], dp[1][2] = a[1][2], dp[1][3] = a[1][3];
  for (int i = 2; i <= n; ++i) {
    dp[i][1] = a[i][1] + min(dp[i - 1][2], dp[i - 1][3]);
    dp[i][2] = a[i][2] + min(dp[i - 1][1], dp[i - 1][3]);
    dp[i][3] = a[i][3] + min(dp[i - 1][1], dp[i - 1][2]);
  }
  long long ans=min(dp[n][1],min(dp[n][2],dp[n][3]));
  cout<<ans;
}