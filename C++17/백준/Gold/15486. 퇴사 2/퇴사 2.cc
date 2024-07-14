#include <iostream>
#include <vector>
using namespace std;
int n;
vector<pair<int, int>> v;
int dp[2000001];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n;
  v.push_back({0, 0});
  for (int i = 1,x, y; i <= n; i++) {
    cin >> x >> y;
    v.push_back({x, y});
  }
  for (int i = n; i >= 1; i--) {
    if(i+v[i].first>n+1) dp[i]=dp[i+1];
    else dp[i]=max(dp[i+1],v[i].second+dp[i+v[i].first]);
  }
  cout<<dp[1];
}