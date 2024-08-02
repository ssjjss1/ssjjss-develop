#include <bits/stdc++.h>
using namespace std;
bool compare(const string &x, const string &y) {
  for (int i = 0; i < min(x.size(), y.size()); i++) {
    if (x[i] != y[i]) {
      if (x[i] == '-')return 0;
      if (y[i] == '-')return 1;
      char X = tolower(x[i]);
      char Y = tolower(y[i]);
      if (X != Y)return X < Y;
      if (x[i] != y[i])return isupper(x[i]);
    }
  }
  return x < y;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end(), compare);
    for (auto i : v)cout << i << "\n";
  }
}