#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int t;
bool f(vector<int> v1[], int x) {
  vector<int> v(x + 4, -1);
  queue<int> q;
  for (int i = 1; i <= x; i++) {
    if (v[i] == -1) {
      v[i] = 0;
      q.push(i);
      while (!q.empty()) {
        int xx = q.front();
        q.pop();
        for (int j : v1[xx]) {
          if (v[j] == -1) {
            v[j] = 1 - v[xx];
            q.push(j);
          } 
          else if (v[j] == v[xx]) return 0;
        }
      }
    }
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> v[n + 4];
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      v[x].push_back(y);
      v[y].push_back(x);
    }
    if (f(v, n)) cout << "YES\n";
    else cout << "NO\n";
  }
}