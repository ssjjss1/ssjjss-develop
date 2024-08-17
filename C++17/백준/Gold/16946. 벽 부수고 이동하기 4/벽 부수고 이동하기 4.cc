#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int n, m;
int a[1004][1004];
int visited[1004][1004];
int gs[1000004];
const int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) a[i][j] = s[j] - '0';
  }
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 0 && visited[i][j] == 0) {
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = cnt;
        int size = 0;
        while (!q.empty()) {
          int x = q.front().first, y = q.front().second;
          q.pop();
          size+=1;
          for (int d = 0; d < 4; d++) {
            int xx = x + dx[d], yy = y + dy[d];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == 0 && !visited[xx][yy]) {
              visited[xx][yy] = cnt;
              q.push({xx, yy});
            }
          }
        }
        gs[cnt] = size;
        cnt++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1) {
        set<int> s;
        int mov = 1;
        for (int d = 0; d < 4; d++) {
          int xx = i + dx[d], yy = j + dy[d];
          if (xx >= 0 && xx < n && yy >= 0 && yy < m && !a[xx][yy]) {
            int cnt = visited[xx][yy];
            if (s.find(cnt) == s.end()) {
              mov += gs[cnt];
              s.insert(cnt);
            }
          }
        }
        cout << mov % 10;
      } 
      else cout << 0;
    }
    cout << '\n';
  }
}