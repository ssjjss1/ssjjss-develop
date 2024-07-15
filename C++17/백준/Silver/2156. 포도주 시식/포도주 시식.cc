#include <bits/stdc++.h>
using namespace std;
int n;
int a[10001],dp[10001];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dp[1] = a[1];
  if (n >= 2)dp[2] = a[1] + a[2];
  for (int i = 3; i <= n; i++) dp[i] = max(dp[i - 1], max(a[i] + dp[i - 2], a[i] + a[i - 1] + dp[i - 3]));
  cout << dp[n];
}