#include <iostream>
#include <vector>
using namespace std;
int t, n;
vector<int> v;
vector<int> visited;
vector<int> finished;
int cnt;
void f(int x) {
  int k = x;
  vector<int> _v;
  while (true) {
    _v.push_back(k);
    visited[k] = 1;
    int next_k = v[k];
    if (visited[next_k]) {
      if (!finished[next_k]) {
        while (!_v.empty()) {
          int xx = _v.back();
          _v.pop_back();
          cnt += 1;
          finished[xx] = 1;
          if (xx == next_k) break;
        }
      }
      break;
    }
    k = next_k;
  }
  while (!_v.empty()) {
    int y = _v.back();
    _v.pop_back();
    finished[y] = 1;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    v.resize(n + 4);
    visited.assign(n + 4, 0);
    finished.assign(n + 4, 0);
    cnt = 0;
    for (int i = 1; i <= n; i++)
      cin >> v[i];
    for (int i = 1; i <= n; i++) {
      if (!visited[i]) {
        f(i);
      }
    }
    cout << n - cnt << "\n";
  }
}