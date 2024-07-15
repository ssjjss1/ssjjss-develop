#include <iostream>
#include <vector>
using namespace std;
int n, m;
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  vector<int> a(m+1);
  for (int i = 0; i < m; i++)cin >> a[i];
  vector<long long> dp(41, 0);
  dp[0]=1;
  dp[1] = 1,dp[2] = 2;
  for (int i = 3; i <= 40; i++)dp[i] = dp[i - 1] + dp[i - 2];
  long long ans = 1;
  int k = 0;
  for (int i = 0; i < m; i++) {
    ans *= dp[a[i] - k - 1];
    k = a[i];
  }
  ans *= dp[n - k];
  cout << ans;
}