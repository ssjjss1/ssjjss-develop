#include <iostream>
using namespace std;
int n, m;
char c1[54][54], c2[54][54];
void f(int x, int y) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      c1[x + i][y + j] = (c1[x + i][y + j] == '0') ? '1' : '0';
    }
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c1[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c2[i][j];
    }
  }
  int cnt = 0;
  for (int i = 0; i <= n - 3; i++) {
    for (int j = 0; j <= m - 3; j++) {
      if (c1[i][j] != c2[i][j]) {
        f(i, j);
        cnt+=1;
      }
    }
  }
  bool flag = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c1[i][j] != c2[i][j]) {
        flag = 0;
        break;
      }
    }
    if (!flag) break;
  }
  if (flag) cout << cnt;
  else cout << -1;
}