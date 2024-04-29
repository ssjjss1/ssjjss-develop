#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<pair<long long int,long long int>> v[200001];
const int inf = 987654321;
int n, m;
int x, y, z;
long long int d[10004];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  fill(d, d + n + 1, inf);
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    v[x - 1].push_back({y - 1, z});
  }
  d[0] = 0;
  bool flag=false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (auto k : v[j]) {
        int d1 = k.second;
        int t = k.first;
        if (d[t] > d[j] + d1 && d[j] != inf) {
          if (i == n - 1)
            flag=true;
          d[t] = d[j] + d1;
        }
      }
    }
  }
  if (flag)
    cout << -1 << "\n";
  else
    for (int i = 1; i < n; i++) {
      cout << (d[i] == inf ? -1 : d[i]) << "\n";
    }
}