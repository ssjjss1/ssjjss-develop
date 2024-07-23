#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n;
long long dp[4][14];
vector<int> v[8] = {{1, 2},{0, 3},{0, 3, 4}, {1, 2, 4, 5},{2, 3, 5, 6}, {3, 4, 6, 7}, {4, 5, 7}, {5, 6}};
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
  cin >> n;
  dp[0][7] = 1;
  for (int p = 1; p <= n; p++){
    for (int i = 0; i <= 7; i++) {
      dp[1][i] = 0;
      for (auto j:v[i]){
        dp[1][i] = (dp[1][i] + dp[0][j]) % mod;
      }
    }
    for (int i = 0; i <= 7; i++) dp[0][i] = dp[1][i];
  }
  cout << dp[0][7];
}