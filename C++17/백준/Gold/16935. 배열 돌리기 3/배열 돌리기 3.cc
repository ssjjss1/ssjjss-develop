#include <cstring>
#include <iostream>
using namespace std;
int n, m, k;
int d[104][104];
void f() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << d[i][j] << " ";
    }
    cout << "\n";
  }
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> d[i][j];
    }
  }
  for (int i = 1, x; i <= k; i++) {
    cin >> x;
    int d1[104][104];
    if (x == 1) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          d1[i][j] = d[n - i + 1][j];
        }
      }
    } 
    else if (x == 2) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          d1[i][j] = d[i][m - j + 1];
        }
      }
    } 
    else if (x == 3) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          d1[j][n - i + 1] = d[i][j];
        }
      }
      swap(n, m);
    } 
    else if (x == 4) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          d1[m - j + 1][i] = d[i][j];
        }
      }
      swap(n, m);
    } 
    else if (x == 5) {
      int xx = n / 2, yy = m / 2;
      for (int i = 1; i <= xx; i++) {
        for (int j = 1; j <= yy; j++) {
          d1[i][j + yy] = d[i][j];
          d1[i + xx][j + yy] = d[i][j + yy];
          d1[i + xx][j] = d[i + xx][j + yy];
          d1[i][j] = d[i + xx][j];
        }
      }
    } 
    else if (x == 6) {
      int xx = n / 2, yy = m / 2;
      for (int i = 1; i <= xx; i++) {
        for (int j = 1; j <= yy; j++) {
          d1[i + xx][j] = d[i][j];
          d1[i + xx][j + yy] = d[i + xx][j];
          d1[i][j + yy] = d[i + xx][j + yy];
          d1[i][j] = d[i][j + yy];
        }
      }
    }
    memcpy(d, d1, sizeof(d1));
  }
  f();
}