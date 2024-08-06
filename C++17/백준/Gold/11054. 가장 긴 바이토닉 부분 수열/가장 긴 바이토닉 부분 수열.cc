#include <iostream>
using namespace std;
int d[1004], dp1[1004], dp2[1004];
int n, mx1, mx2, mx3;
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> d[i];
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j < i; j++) {
      if (d[i] > d[j] && dp1[j] > cnt) cnt = dp1[j];
    }
    dp1[i] = cnt + 1;
    mx2 = max(mx2, dp1[i]);
  }
  for (int i = n; i >= 1; i--) {
    int cnt = 0;
    for (int j = n; j > i; j--) {
      if (d[i] > d[j] && dp2[j] > cnt) cnt = dp2[j];
    }
    dp2[i] = cnt + 1;
    mx2 = max(mx2, dp2[i]);
  }
  for (int i = 1; i <= n; i++) mx3 = max(mx3, dp1[i] + dp2[i]);
  cout << mx3 - 1 ;
}