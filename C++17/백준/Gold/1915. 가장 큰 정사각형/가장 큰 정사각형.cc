#include <algorithm>
#include <iostream>
#include <vector>
int n, m;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  vector<vector<int>> dp(n, vector<int>(m, 0));
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1) {
        if (i == 0 || j == 0) dp[i][j] = 1;
        else dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
        mx = max(mx, dp[i][j]);
      }
    }
  }
  cout<<mx * mx;
}