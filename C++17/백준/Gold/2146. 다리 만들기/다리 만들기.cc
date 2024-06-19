#include<iostream>
#include<queue>
using namespace std;
int n;
const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };
int a[201][201];
int visited[201][201];
int mn = 1e9;
struct P {
  int b, c, d;
};
int f(int x, int y, int t) {
  int visited1[201][201];
  fill(&visited1[0][0], &visited1[0][0] + 201 * 201, 0);
  visited1[x][y] = 1;
  queue<P> q;
  q.push({ x,y,1 });
  while (!q.empty()) {
    int x = q.front().b, y = q.front().c, cnt = q.front().d;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i], yy = y + dy[i];
      if(mn<=cnt) return 1e9;
      if (xx<1 || yy<1 || xx>n || yy>n || a[xx][yy] == t || visited1[xx][yy]) continue;
      if (a[xx][yy] != t && a[xx][yy]!=0) return cnt;
      visited1[xx][yy] = 1;
      q.push({ xx,yy,cnt + 1 });
    }
  }
  return 1e9;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  int k = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (!visited[i][j]&&a[i][j]) {
        queue<pair<int, int>> q;
        visited[i][j] = 1;
        q.push({ i,j });
        while (!q.empty()) {
          int x = q.front().first, y = q.front().second;
          a[x][y] = k;
          q.pop();
          for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx<1 || yy<1 || xx>n || yy>n || visited[xx][yy] || !a[xx][yy]) continue;
            visited[xx][yy] = 1;
            q.push({ xx,yy });
          }
        }
        k += 1;
      }
    }
  }
  fill(&visited[0][0], &visited[0][0] + 201 * 201, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (!visited[i][j] && a[i][j]!=0) {
        queue<pair<int,int>> q;
        visited[i][j] = 1;
        q.push({ i,j });
        while (!q.empty()) {
          int x = q.front().first, y = q.front().second;
          q.pop();
          for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx<1 || yy<1 || xx>n || yy>n || visited[xx][yy]) continue;
            else if (!a[xx][yy]){
              int p= f(xx, yy, a[x][y]);
              mn = min(mn,p);
              continue;
            }
            else q.push({ xx,yy });
            visited[xx][yy] = 1;
          }
        }
      }
    }
  }
  cout << mn;
}