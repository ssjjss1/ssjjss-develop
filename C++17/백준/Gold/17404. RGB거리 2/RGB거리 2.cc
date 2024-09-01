#include<iostream>
using namespace std;
const int inf = 1e9 + 4;
int n;
int d[1004][4], dp[1004][4];
int main(){
  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> d[i][j];
    }
  }
  int ans = inf;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++){
      if (i == j) dp[0][j] = d[0][j];
      else dp[0][j] = inf;
    }
    for (int j = 1; j < n; j++){
      dp[j][0] = d[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
      dp[j][1] = d[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
      dp[j][2] = d[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
    }
    for (int j = 0; j < 3; j++){
      if (i == j) continue;
      else ans = min(ans, dp[n - 1][j]);
    }
  }
  cout << ans;
}