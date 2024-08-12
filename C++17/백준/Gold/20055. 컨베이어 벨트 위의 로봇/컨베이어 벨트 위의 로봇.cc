#include <iostream>
#include <vector>
using namespace std;
int n, k;
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  vector<int> d(2 * n + 4);
  vector<bool> r(n + 4, 0);
  for (int i = 0; i < 2 * n; i++) cin >> d[i];
  int ans = 0;
  while (true) {
    ans += 1;
    int nxt = d[2 * n - 1];
    for (int i = 2 * n - 1; i > 0; i--) d[i] = d[i - 1];
    d[0] = nxt;
    for (int i = n - 1; i > 0; i--) r[i] = r[i - 1];
    r[0] = 0;
    if (r[n - 1]) r[n - 1] = 0;
    for (int i = n - 1; i > 0; i--) {
      if (r[i - 1] && !r[i] && d[i] > 0) {
        r[i] = 1;
        r[i - 1] = 0;
        d[i] -= 1;
        if (i == n - 1) r[i] = 0;
      }
    }
    if (d[0] > 0) {
      r[0] = 1;
      d[0]-=1;
    }
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++) if (d[i] == 0) cnt += 1;
    if (cnt >= k) {
      cout << ans << "\n";
      break;
    }
  }
}