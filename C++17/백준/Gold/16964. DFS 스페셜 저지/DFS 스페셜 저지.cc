#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int order[100004], d[100004];
vector<int> v[100004];
bool visited[100004];
int cnt = 1;
void f(int x) {
  visited[x] = 1;
  for (auto i : v[x]) {
    if (!visited[i]) {
      if (d[++cnt] != i) {
        cout << 0;
        exit(0);
      }
      f(i);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n;
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
    order[d[i]] = i;
  }
  if (d[1] != 1) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= n; i++)sort(v[i].begin(), v[i].end(), [](int a, int b) { return order[a] < order[b]; });
  f(1);
  cout << 1;
}