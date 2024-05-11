#include <iostream>
#include <queue>
using namespace std;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
struct A {
  int x, y, z;
};
int n, m, k;
int a[1004][1004], b[1004][1004];
int visited[1004][1004][50];
void f() {
  queue<A> q;
  q.push({1, 1, 0});
  visited[0][0][0] = 1;
  visited[0][0][1] = 1;
  b[1][1] = 1;
  while (!q.empty()) {
    int x = q.front().x;
    int y = q.front().y;
    int w = q.front().z;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx > 0 && xx <= n && yy > 0 && yy <= m) {
        if (w < k && a[xx][yy] && !visited[xx][yy][w + 1]) {
          visited[xx][yy][w + 1] = 1;
          b[xx][yy] = b[x][y] + 1;
          q.push({xx, yy, w + 1});
        }
        if (!a[xx][yy] && !visited[xx][yy][w]) {
          visited[xx][yy][w] = 1;
          b[xx][yy] = b[x][y] + 1;
          q.push({xx, yy, w});
        }
        if (xx == n && yy == m) {
          cout << b[n][m];
          return;
        }
      }
    }
  }
  cout << -1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  if (n == 1 && m == 1) {
    cout << 1;
    return 0;
  }
  f();
}