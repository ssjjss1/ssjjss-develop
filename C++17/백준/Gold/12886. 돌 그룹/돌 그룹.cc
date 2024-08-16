#include <iostream>
#include <queue>
using namespace std;
int a, b, c;
bool visited[1501][1501];
void f(int a, int b, int c) {
  int sum = a + b + c;
  queue<pair<int, int>> q;
  q.push({a, b});
  visited[a][b] = 1;
  while (!q.empty()) {
    int x = q.front().first,  y = q.front().second;
    int z = sum - x - y;
    q.pop();
    if (x == y && y == z) {
      cout << 1;
      return;
    }
    int dx[] = {x, x, y};
    int dy[] = {y, z, z};
    for (int i = 0; i < 3; i++) {
      int xx = dx[i], yy = dy[i];
      if (xx < yy) {
        yy -= xx;
        xx += xx;
      } 
      else {
        xx -= yy;
        yy += yy;
      }
      int mn = min(xx, yy), mx = max(xx, yy);
      if (!visited[mn][mx]) {
        visited[mn][mx] = 1;
        q.push({mn, mx});
      }
    }
  }
  cout << 0;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> a >> b >> c;
  if ((a + b + c) % 3 != 0) cout << 0;
  else f(a, b, c);
}