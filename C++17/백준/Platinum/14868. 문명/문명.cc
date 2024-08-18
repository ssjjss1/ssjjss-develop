#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int p[2004 * 2004];
bool visited[2004][2004];
vector<pair<int, int>> v;
int f(int x) {
  if (p[x] == x) return x;
  return p[x] = f(p[x]);
}
void g(int a, int b) {
  a = f(a), b = f(b);
  if (a != b) p[b] = a;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  queue<pair<int, int>> q, q2;
  for (int i = 1; i <= n * n; i++) p[i] = i;
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    visited[x][y] = 1;
    q.push({x, y});
    q2.push({x, y});
  }
  int cnt = 0;
  int k = m;
  while (!q.empty()) {
    int size = q.size();
    while (!q2.empty()) {
      int x = q2.front().first, y = q2.front().second;
      q2.pop();
      int cp = (x - 1) * n + y;
      for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > n) continue;
        int np = (xx - 1) * n + yy;
        if (visited[xx][yy]) {
          if (f(cp) != f(np)) {
            g(cp, np);
            k -= 1;
            if (k == 1) {
              cout << cnt;
              return 0;
            }
          }
        }
      }
    }
    while (size--) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      int cp = (x - 1) * n + y;
      for (int j = 0; j < 4; j++) {
        int xx = x + dx[j], yy = y + dy[j];
        if (xx < 1 || xx > n || yy < 1 || yy > n)
          continue;
        int np = (xx - 1) * n + yy;
        if (visited[xx][yy]) {
          if (f(cp) != f(np)) {
            g(cp, np);
            k -= 1;
          }
        } else {
          visited[xx][yy] = 1;
          p[np] = f(cp);
          q.push({xx, yy});
          q2.push({xx, yy});
        }
      }
    }
    cnt += 1;
    if (k == 1) {
      cout << cnt;
      return 0;
    }
  }
}