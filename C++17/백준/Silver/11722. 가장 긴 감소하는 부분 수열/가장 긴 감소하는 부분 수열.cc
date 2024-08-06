#include <iostream>
using namespace std;
int d[1004], dp[1004];
int n, mx;
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> d[i];
  for (int i = n; i >= 1; i--) {
    int cnt = 0;
    for (int j = n; j > i; j--) {
      if (d[i] > d[j] && dp[j] > cnt) cnt = dp[j];
    }
    dp[i] = cnt + 1;
    mx = max(mx, dp[i]);
  }
  cout << mx;
}