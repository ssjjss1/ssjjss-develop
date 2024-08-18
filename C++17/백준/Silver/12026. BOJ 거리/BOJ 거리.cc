#include <iostream>
using namespace std;
int n;
string s;
int dp[1004];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> s;
  fill(dp, dp + 1004, 1e9);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    if (dp[i] == 1e9)continue; 
    for (int j = i + 1; j < n; j++) {
      if ((s[i] == 'B' && s[j] == 'O') || (s[i] == 'O' && s[j] == 'J') || (s[i] == 'J' && s[j] == 'B')) {
        dp[j] = min(dp[j], dp[i] + (j - i) * (j - i));
      }
    }
  }
  if (dp[n - 1] == 1e9) cout << -1;
  else cout << dp[n - 1]; 
}