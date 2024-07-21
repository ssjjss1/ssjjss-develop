#include <iostream>
using namespace std;
typedef long long ll;
ll n, m, s;
ll ans = 0;
ll a[200004];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)cin >> a[i];
  s = 1;
  for (int i = 1; i <= n; i++) {
    if((ans|a[i])>m||(a[i]|m)!=m){
      ans=0;
      s=i+1;
      continue;
    }
    ans |= a[i];
    if (ans == m) {
      cout << s << " " << i;
      return 0;
    }
  }
  cout << -1;
}