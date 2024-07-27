#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int d[1004];
vector<pair<pair<int, int>, int>> v;
int f(int x) {
  if (d[x] == x)return x;
  return d[x] = f(d[x]);
}
void g(int x, int y) {
  int a = f(x), b = f(y);
  if (a != b)d[a] = b;
}
bool compare1(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {return a.second < b.second;}
bool compare2(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {return a.second > b.second;}
int h(bool flag) {
  vector<pair<pair<int, int>, int>> v1 = v;
  if (flag) sort(v1.begin(), v1.end(), compare2);
  else sort(v1.begin(), v1.end(), compare1);
  fill(d,d+1004,0);
  for (int i = 1; i <= n; i++) d[i] = i;
  int cnt = 0;
  for (auto i : v1) {
    int x = i.first.first, y = i.first.second, w = i.second;
    if (f(x) != f(y)) {
      g(x, y);
      if (w == 0) cnt += 1;
    }
  }
  return cnt * cnt;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i = 0, x, y, z; i <= m; i++) {
    cin >> x >> y >> z;
    v.push_back({{x, y}, z});
  }
  int cnt1 = h(0);
  int cnt2 = h(1);
  cout << cnt1 - cnt2;
}