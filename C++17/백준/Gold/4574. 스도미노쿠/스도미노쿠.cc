#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector<vector<int>> v(10, vector<int>(10, 0));
vector<vector<int>> visited(10, vector<int>(10, 0));
vector<pair<int, int>> d = {
    {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {1, 8}, {1, 9}, {2, 3},
    {2, 4}, {2, 5}, {2, 6}, {2, 7}, {2, 8}, {2, 9}, {3, 4}, {3, 5}, {3, 6},
    {3, 7}, {3, 8}, {3, 9}, {4, 5}, {4, 6}, {4, 7}, {4, 8}, {4, 9}, {5, 6},
    {5, 7}, {5, 8}, {5, 9}, {6, 7}, {6, 8}, {6, 9}, {7, 8}, {7, 9}, {8, 9}};
bool g(int x, int y, int t) {
  for (int i = 1; i <= 9; i++) {
    if (v[x][i] == t || v[i][y] == t)
      return false;
  }
  int xx = (x - 1) / 3 * 3 + 1, yy = (y - 1) / 3 * 3 + 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (v[xx + i][yy + j] == t)
        return false;
    }
  }
  return true;
}
bool f(int cnt) {
  if (cnt == 36) return true;
  for (int i = 1; i <= 9; i++) {
    for (int j = 1; j <= 9; j++) {
      if (v[i][j] == 0) {
        for (auto &p : d) {
          int a = p.first, b = p.second;
          if (!visited[a][b]) {
            if (j + 1 <= 9 && v[i][j + 1] == 0 && g(i, j, a) && g(i, j + 1, b)) {
              visited[a][b] = visited[b][a] = 1;
              v[i][j] = a, v[i][j + 1] = b;
              if (f(cnt + 1))
                return true;
              v[i][j] = v[i][j + 1] = 0;
              visited[a][b] = visited[b][a] = 0;
            }
            if (j + 1 <= 9 && v[i][j + 1] == 0 && g(i, j, b) && g(i, j + 1, a)) {
              visited[a][b] = visited[b][a] = 1;
              v[i][j] = b, v[i][j + 1] = a;
              if (f(cnt + 1))
                return true;
              v[i][j] = v[i][j + 1] = 0;
              visited[a][b] = visited[b][a] = 0;
            }
            if (i + 1 <= 9 && v[i + 1][j] == 0 && g(i, j, a) && g(i + 1, j, b)) {
              visited[a][b] = visited[b][a] = 1;
              v[i][j] = a, v[i + 1][j] = b;
              if (f(cnt + 1))
                return true;
              v[i][j] = v[i + 1][j] = 0;
              visited[a][b] = visited[b][a] = 0;
            }
            if (i + 1 <= 9 && v[i + 1][j] == 0 && g(i, j, b) && g(i + 1, j, a)) {
              visited[a][b] = visited[b][a] = 1;
              v[i][j] = b, v[i + 1][j] = a;
              if (f(cnt + 1))
                return true;
              v[i][j] = v[i + 1][j] = 0;
              visited[a][b] = visited[b][a] = 0;
            }
          }
        }
        return false;
      }
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int cnt = 0;
  while (true) {
    cin >> n;
    if (n == 0) break;
    v.assign(10, vector<int>(10, 0));
    visited.assign(10, vector<int>(10, 0));
    for (int i = 1, x, y; i <= n; i++) {
      string s1, s2;
      cin >> x >> s1 >> y >> s2;
      int r1 = s1[0] - 'A' + 1, c1 = s1[1] - '0';
      int r2 = s2[0] - 'A' + 1, c2 = s2[1] - '0';
      v[r1][c1] = x;
      v[r2][c2] = y;
      visited[x][y] = visited[y][x] = 1;
    }
    for (int i = 1; i <= 9; i++) {
      string s;
      cin >> s;
      v[s[0] - 'A' + 1][s[1] - '0'] = i;
    }
    f(n);
    cout << "Puzzle " << ++cnt << "\n";
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {
        cout << v[i][j];
      }
      cout << "\n";
    }
  }
}