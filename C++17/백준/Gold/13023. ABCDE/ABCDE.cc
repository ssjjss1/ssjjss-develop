#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<vector<int>> v;
vector<bool> visited;
bool f(int x, int cnt) {
  if (cnt == 4) return 1;
  visited[x] = 1;
  for (int i : v[x]) {
    if (!visited[i]) {
      if (f(i, cnt + 1)) return 1;
    }
  }
  visited[x] = 0;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  v.resize(n + 4);
  visited.resize(n + 4, 0);
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 0; i < n; i++) {
    if (f(i, 0)) {
      cout << 1;
      return 0;
    }
  }
  cout << 0;
}