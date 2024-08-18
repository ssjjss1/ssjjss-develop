#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<ll, string> visited;
ll s, t;
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> s >> t;
  if (s == t) {
    cout << 0 << "\n";
    return 0;
  }
  queue<pair<ll, string>> q;
  q.push({s, ""});
  visited[s] = "";
  while (!q.empty()) {
    ll x = q.front().first;
    string st = q.front().second;
    q.pop();
    if (x == t) {
      cout << st << "\n";
      return 0;
    }
    if (x * x <= t && visited.find(x * x) == visited.end()) {
      visited[x * x] = st + "*";
      q.push({x * x, st + "*"});
    }
    if (x + x <= t && visited.find(x + x) == visited.end()) {
      visited[x + x] = st + "+";
      q.push({x + x, st + "+"});
    }
    if (visited.find(0) == visited.end()) {
      visited[0] = st + "-";
      q.push({0, st + "-"});
    }
    if (visited.find(1) == visited.end()) {
      visited[1] = st + "/";
      q.push({1, st + "/"});
    }
  }
  cout << -1;
}