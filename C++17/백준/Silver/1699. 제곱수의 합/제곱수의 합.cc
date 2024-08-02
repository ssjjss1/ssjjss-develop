#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  vector<int> dp(n+4,1e9);
  dp[0] = 0;
  for (int i = 1; i * i <= n; i++) {
    for (int j = i * i; j <= n; j++) {
      dp[j] = min(dp[j], dp[j - i * i] + 1);
    }
  }
  cout << dp[n];
}