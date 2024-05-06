#include <bits/stdc++.h>
using namespace std;
int n, m;
deque<pair<int, int>> dq;
int main() {
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin>>x;
    if(dq.size() && dq.front().second <= i - m)dq.pop_front();
    while (!dq.empty() && dq.back().first > x)dq.pop_back();
    dq.push_back({x, i});
    cout << dq.front().first << " ";
  }
}