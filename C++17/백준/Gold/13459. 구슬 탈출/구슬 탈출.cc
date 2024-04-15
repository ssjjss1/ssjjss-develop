#include<iostream>

#include<queue>

using namespace std;

int n, m;

int x1, y1, x2, y2;

int visited[11][11][11][11];

char k[11][11];

const int dx[] = { 1,0,-1,0 }, dy[] = { 0,1,0,-1 };

struct A {

  int a, b, c, d, e;

};

bool g(int x, int y,int xx, int yy, int wx, int wy) {

  while (true) {

    xx += wx, yy+=wy;

    if (x == xx && y == yy) {

      return 1;

    }

    if (k[xx][yy] != '.') return 0;

  }

}

void f() {

  visited[x1][y1][x2][y2] = 1;

  queue<A> q;

  q.push({ x1,y1,x2,y2,1 });

  while (!q.empty()) {

    int x3 = q.front().a, y3 = q.front().b;

    int x4 = q.front().c, y4 = q.front().d;

    int cnt = q.front().e;

    q.pop();

    for (int i = 0; i < 4; i++) {

      int xx1=x3,yy1=y3,xx2=x4,yy2=y4,cnt1=cnt;

      bool flag1 = false, flag2 = false;

      if (g(xx1, yy1, xx2, yy2, dx[i], dy[i])) {

        while (1) {

          xx1 += dx[i], yy1 += dy[i];

          if (k[xx1][yy1] == 'O') {

            flag1 = true;

            break;

          }

          if (k[xx1][yy1] == '#') {

            xx1 -= dx[i], yy1 -= dy[i];

            break;

          }

        }

        while (1) {

          xx2 += dx[i], yy2 += dy[i];

          if (k[xx2][yy2] == 'O') {

            flag2 = true;

            break;

          }

          if (xx1 == xx2 && yy1 == yy2) {

            xx2 -= dx[i], yy2 -= dy[i];

            break;

          }

          if (k[xx2][yy2] == '#') {

            xx2 -= dx[i], yy2 -= dy[i];

            break;

          }

        }

      }

      else {

        while (1) {

          xx2 += dx[i], yy2 += dy[i];

          if (k[xx2][yy2] == 'O') {

            flag2 = true;

            break;

          }

          if (k[xx2][yy2] == '#') {

            xx2 -= dx[i], yy2 -= dy[i];

            break;

          }

        }

        while (1) {

          xx1 += dx[i], yy1 += dy[i];

          if (k[xx1][yy1] == 'O') {

            flag1 = true;

            break;

          }

          if (xx1 == xx2 && yy1 == yy2) {

            xx1 -= dx[i], yy1 -= dy[i];

            break;

          }

          if (k[xx1][yy1] == '#') {

            xx1 -= dx[i], yy1 -= dy[i];

            break;

          }

        }

      }

      if (flag1 && !flag2) {

        cout << 1;

        return;

      }

      if (flag2||(visited[xx1][yy1][xx2][yy2]==1)||cnt1==10) continue;

      visited[xx1][yy1][xx2][yy2] = 1;

      q.push({ xx1,yy1,xx2,yy2,cnt1 + 1 });

    }

  }

  cout <<0;

}

int main() {

  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {

    for (int j = 1; j <= m; j++) {

      char c;

      cin >> c;

      if (c == 'R') x1 = i, y1 = j, k[i][j] = '.';

      else if (c == 'B')x2 = i, y2 = j, k[i][j] = '.';

      else k[i][j] = c;

    }

  }

  f();

}