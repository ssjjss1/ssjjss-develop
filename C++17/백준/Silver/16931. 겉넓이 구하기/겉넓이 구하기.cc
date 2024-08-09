#include <iostream>
using namespace std;
int n, m;
int d[104][104];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> d[i][j];
    }
  }
  int sum = 2 * n * m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      sum += max(0, d[i][j] - d[i][j - 1]);
      sum += max(0, d[i][j] - d[i][j + 1]);
      sum += max(0, d[i][j] - d[i - 1][j]);
      sum += max(0, d[i][j] - d[i + 1][j]);
    }
  }
  cout << sum;
}