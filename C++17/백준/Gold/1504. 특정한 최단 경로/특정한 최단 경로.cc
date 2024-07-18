#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define inf 1e9
using namespace std;
int n, m;
int v1, v2;
vector<pair<int, int>> v[200004];
vector<int> f(int x) {
  vector<int> visited(n + 1, inf);
  priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> q;
  visited[x] = 0;
  q.push({0, x});
  while (!q.empty()) {
    int _x = q.top().second;
    int y = q.top().first;
    q.pop();
    if (y > visited[_x]) continue;
    for (auto i : v[_x]) {
      int xx = i.first, yy = i.second;
      if (visited[_x] + yy < visited[xx]) {
        visited[xx] = visited[_x] + yy;
        q.push({visited[xx], xx});
      }
    }
  }
  return visited;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i = 0, x, y, z; i < m; i++) {
    cin >> x >> y >> z;
    v[x].push_back({y, z});
    v[y].push_back({x, z});
  }
  cin >> v1 >> v2;
  vector<int> df1 = f(1);
  vector<int> dfv1 = f(v1);
  vector<int> dfv2 = f(v2);
  int y1 = df1[v1] + dfv1[v2] + dfv2[n];
  int y2 = df1[v2] + dfv2[v1] + dfv1[n];
  int ans = min(y1, y2);
  if (ans >= inf||ans<=0)cout << -1;
  else cout << ans;
}