#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> v[100004];
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cin.tie(0);
  cin >> n;
  for (int i = 1, x, y; i <= n - 1; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  cin >> m;
  for (int i = 1, x, y; i <= m; i++) {
    cin >> x >> y;
    if (x == 1)cout << (v[y].size() <= 1 ? "no" : "yes") << "\n";
    else if (x == 2) cout<<"yes"<<"\n";
  }
}