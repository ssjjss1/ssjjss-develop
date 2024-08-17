#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char c[14][14];
vector<pair<int, int>> v;
const int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  for (int i = 1; i <= 8; i++) {
    for (int j = 1; j <= 8; j++) {
      cin >> c[i][j];
      if (c[i][j] == '#') {
        v.push_back({i, j});
      }
    }
  }
  queue<pair<int, int>> q;
  q.push({8, 1});
  while (!q.empty()) {
    int size = q.size();
    vector<vector<bool>> visited(9, vector<bool>(9, 0));
    for (int i = 0; i < size; i++) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      if (c[x][y] == '#') continue;
      if (x == 1 && y == 8) {
        cout << 1;
        return 0;
      }
      for (int j = 0; j < 9; j++) {
        int xx = x + dx[j], yy = y + dy[j];
        if(xx < 1 || xx > 8 || yy < 1 || yy > 8 || c[xx][yy] != '.') continue;
        if (!visited[xx][yy]) {
          visited[xx][yy] = 1;
          q.push({xx, yy});
        }
      }
    }
    for (int i = 8; i >= 1; i--) {
      for (int j = 1; j <= 8; j++) {
        if (c[i][j] == '#') {
          c[i][j] = '.';
          if (i < 8) {
            c[i + 1][j] = '#';
          }
        }
      }
    }
  }
  cout << 0;
}