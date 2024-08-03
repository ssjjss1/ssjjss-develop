#include <iostream>
using namespace std;
int n, m;
char c[504][1004];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= 3 * n; i++) {
    for (int j = 1; j <= 8 * m; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int X = 3 * (i - 1) + 1;
      int Y = 8 * (j - 1) + 1;
      int x = c[X + 1][Y + 1] - '0';
      int y = c[X + 1][Y + 3] - '0';
      int z, size;
      if (c[X + 1][Y + 6] != '.') {
        z = (c[X + 1][Y + 5] - '0')*10+c[X + 1][Y + 6] - '0';;
        size = 6;
      } 
      else {
        z = c[X + 1][Y + 5] - '0';
        size = 5;
      }
      bool flag = (x + y == z);
      if (flag) {
        for (int i = X; i <= X + 2; i++) {
          if(i==X+1) c[i][Y]='*',c[i][Y+size+1]='*';
          else {
            for(int j=Y+1;j<=Y+size;j++){
              c[i][j]='*';
            }
          }
        }
      } else {
        c[X + 2][Y + 1] = '/';
        c[X + 1][Y + 2] = '/';
        c[X][Y + 3] = '/';
      }
    }
  }
  for (int i = 1; i <= 3 * n; i++) {
    for (int j = 1; j <= 8 * m; j++) {
      cout << c[i][j];
    }
    cout << '\n';
  }
}