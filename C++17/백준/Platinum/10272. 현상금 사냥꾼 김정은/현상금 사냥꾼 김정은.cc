#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int t, n;
const double inf = 987654321.0;
int a[513], b[513];
double d[513][513];
double g(int x, int y) {
  return sqrt((a[x] - a[y]) * (a[x] - a[y]) + (b[x] - b[y]) * (b[x] - b[y]));
}
double f(int x, int y) {
  double &ref = d[x][y];
  if (ref != inf)
    return ref;
  if (x == n || y == n)
    return ref = g(x, y);
  int k = max(x, y) + 1;
  return ref = min(f(k, y) + g(x, k), f(x, k) + g(k, y));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i] >> b[i];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++)
        d[i][j] = inf;
    cout << fixed << setprecision(20) << f(1, 1) << "\n";
  }
}