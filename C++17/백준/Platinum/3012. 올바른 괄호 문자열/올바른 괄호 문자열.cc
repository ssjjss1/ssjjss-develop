#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 100000;
int n;
string s;
ll dp[204][204];
char c1[] = {'(', '{', '['}, c2[] = {')', '}', ']'};
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> s;
  memset(dp, 0, sizeof(dp));
  if(n%2){
    cout<<0;
    return 0;
  }
  for (int l = 2; l <= n; l += 2) {
    for (int x = 0; x < n - l + 1; x++) {
      int y = x + l - 1;
      for (int i = x + 1; i <= y; i += 2) {
        for (int j = 0; j < 3; j++) {
          if ((s[x] == c1[j] || s[x] == '?') && (s[i] == c2[j] || s[i] == '?')) {
            ll t = 1;
            if (x + 1 <= i - 1) t *= dp[x + 1][i - 1];
            if (i + 1 <= y) t *= dp[i + 1][y];
            dp[x][y] += t;
            if(dp[x][y]>mod) dp[x][y]%=mod, dp[x][y]+=mod;
          }
        }
      }
    }
  }
  string s1=to_string(dp[0][n-1]);
  if(s1.size()<=5) cout<<s1;
  else cout << s1.substr(s1.length()-5, s1.length() - 1);
}
