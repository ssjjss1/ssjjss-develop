#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;
int in[100004];
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> m;
  vector<int> v[100004];
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    in[y] += 1;
  }
  priority_queue<int,vector<int>,greater<int>> q;
  for (int i = 1; i <= n; i++) if (!in[i]) q.push(i);
  while (!q.empty()) {
    int x = q.top();
    q.pop();
    cout << x << " ";
    for (auto i : v[x]) {
      if (!--in[i])q.push(i);
    }
  }
}