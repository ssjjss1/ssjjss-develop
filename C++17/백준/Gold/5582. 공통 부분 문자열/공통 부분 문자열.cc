#include <iostream>
#include <string>
using namespace std;
string s1, s2;
int dp[4004][4004];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> s1 >> s2;
  int mx = 0;
  for (int i = 1; i <= s1.length(); i++) {
    for (int j = 1; j <= s2.length(); j++) {
      if (s1[i-1] == s2[j-1]) {
        dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        mx = max(mx, dp[i][j]);
      } 
      else dp[i][j] = 0;
    }
  }
  cout << mx;
}