#include <iostream>
using namespace std;
int n, k;
int dp[31][31][31][504]; 
bool f(int x, int y, int z, int sum, string s) {
  if (x + y + z == n) {
    if (sum == k) {
      cout << s;
      return 1;
    }
    return 0;
  }
  if (dp[x][y][z][sum] != -1)  return 0;
  dp[x][y][z][sum] = 0;
  if (f(x + 1, y, z, sum, s + 'A')) return 1;
  if (f(x, y + 1, z, sum + x, s + 'B')) return 1;
  if (f(x, y, z + 1, sum + x + y, s + 'C')) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int l = 0; l <= n; l++) {
        for (int m = 0; m <= 503; m++) {
          dp[i][j][l][m] = -1;
        }
      }
    }
  }
  if (!f(0, 0, 0, 0, "")) cout << -1;
}