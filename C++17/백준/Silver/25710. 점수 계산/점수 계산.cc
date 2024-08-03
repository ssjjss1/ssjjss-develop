#include <bits/stdc++.h>
using namespace std;
int n, ans;
int f(int x) {
  int sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return sum;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin>>n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)cin >> a[i];
  map<int, int> ma;
  for (auto i : a)ma[i] += 1;
  vector<int> v;
  for (auto i : ma)v.push_back(i.first);
  for (int i = 0; i < v.size(); i++) {
    int j = (ma[v[i]] > 1) ? i : i + 1;
    for (; j < v.size(); j++) {
      int x = v[i] * v[j];
      ans = max(f(x), ans);
    }
  }
  cout << ans;
}