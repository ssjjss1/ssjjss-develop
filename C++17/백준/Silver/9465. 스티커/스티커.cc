#include <iostream>
using namespace std;
int t;
int a[100004][3], dp[100004][3];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> a[j][i];
      }
    }
    fill(&dp[0][0],&dp[0][0]+100004*3,0); 
    dp[1][0] = 0, dp[1][1] = a[1][1], dp[1][2] = a[1][2];
    for (int j = 2; j <= n; j++) {
      dp[j][0] = max(dp[j - 1][0], max(dp[j - 1][1], dp[j - 1][2]));
      dp[j][1] = max(dp[j - 1][0], dp[j - 1][2]) + a[j][1];
      dp[j][2] = max(dp[j - 1][0], dp[j - 1][1]) + a[j][2];
    }
    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << '\n';
  }
}