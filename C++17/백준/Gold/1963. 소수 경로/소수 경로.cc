#include <bits/stdc++.h>
using namespace std;
int n;
const int p[] = {1, 10, 100, 1000};
int visited[10004];
int d[10004];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i = 2; i <= 10000; i++) {
    if (visited[i]) continue;
    for (int j = 2 * i; j <= 10000; j += i) visited[j] = 1;
  }
  while (n--) {
    int a, b;
    cin >> a >> b;
    fill(d, d + 10004, 0);
    queue<pair<int, int>> q;
    q.push({a, 0});
    d[a] = 1;
    bool flag = 0;
    while (!q.empty()) {
      int x = q.front().first, cnt = q.front().second;
      q.pop();
      if (x == b) {
        cout << cnt << "\n";
        flag = 1;
        break;
      }
      for (int i = 0; i < 4; i++) {
        int cx = (x / p[i]) % 10;
        for (int j = 0; j <= 9; j++) {
          if (i == 3 && j == 0) continue;
          int xx = x + (j - cx) * p[i];
          if (xx >= 1000 && !visited[xx] && !d[xx]) {
            d[xx] = 1;
            q.push({xx, cnt + 1});
          }
        }
      }
    }
    if (!flag) cout << "Impossible\n";
  }
}