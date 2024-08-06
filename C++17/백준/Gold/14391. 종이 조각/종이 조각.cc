#include <algorithm>
#include <iostream>
using namespace std;
int n, m, mx;
int d[5][5];
void f(int bit, int sum) {
  if (bit == (1 << (n * m)) - 1) {
    mx = max(mx, sum);
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!(bit & (1 << (i * m + j)))) {
        int ans1 = 0;
        int bit1 = bit;
        for (int k = j; k < m; k++) {
          if (bit1 & (1 << (i * m + k))) break;
          ans1 = ans1 * 10 + d[i][k];
          bit1 |= (1 << (i * m + k));
          f(bit1, sum + ans1);
        }
        int ans2 = 0;
        int bit2 = bit;
        for (int k = i; k < n; k++) {
          if (bit2 & (1 << (k * m + j))) break;
          ans2 = ans2 * 10 + d[k][j];
          bit2 |= (1 << (k * m + j));
          f(bit2, sum + ans2);
        }
        return;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      d[i][j] = c - '0';
    }
  }
  mx = 0;
  f(0, 0);
  cout << mx;
}